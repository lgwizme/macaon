/* Copyright (C) Alejandro Acosta 2005/2006 
 * Distributed under GPL License. See COPYING. 
 *
 * main.cpp
 * segmenter
 *
 * AA 2005
 * MODIFIED 2006/12/16 */

#define _MODIFIED_MONTH_ "2006/12"

#define _TXT2XMLMODE 200
#define _TXT2TXTMODE 201
#define _XML2XMLMODE 202

#define _ID_PREFIX_SECTION "sn"
#define _ID_PREFIX_PARAGRAPH "p"
#define _ID_PREFIX_SENTENCE "s"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <time.h>
#include <unistd.h> // getopt


#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

#include "XMLInterface.hh"
#include "StreamSegmenter.h"
#include "DefaultDict.h"
#include "Version.h"

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>

#ifdef _INSTALLED_NAME_
#define _PREFIX_ "[" _INSTALLED_NAME_ "] "
#else
#define _PREFIX_ ""
#endif

XERCES_CPP_NAMESPACE_USE
using namespace std;

XMLInterface* xmlInterface;
StreamSegmenter* seg;
string affectedSections;
bool verbose;
bool stamp;

/* FUNCTION DECLARATIONS */
int addSegmentedParagraphToSection(vector<string> par, DOMElement* sect, const
char* pid);
string getTimestamp();
void stampDocument(DOMElement* root);
void usage();
void version();
void handleFile(char* filein, char* fileout, int mode);
void handleDocument(DOMDocument* document, char* outputfile);
string getFileContents(char* filename);


void version() {
  cerr << _INSTALLED_NAME_ << " version " << _VERSION_ << endl
       << "Built on " << _BUILT_ << endl
       << "On a " << _MACHINE_ << " by " << _BUILDER_ << endl;      
}

void usage() {
  cout << 
    "-----------------------------------------------------------------------------\n" <<
    _INSTALLED_NAME_ " v"<< _VERSION_ <<" (" << _MODIFIED_MONTH_<< ") by Alejandro Acosta\n" <<
    "-----------------------------------------------------------------------------\n" <<
    "USAGE   : " << _INSTALLED_NAME_ << " [options]\n" <<
    "OPTIONS :\n" <<
    "   -h               show this message\n" <<
    "   -V               show version info and exit\n"
    "   -v               verbose mode (print messages)\n" <<
    "   -d               print boundary word set and exit\n" <<
    "   -i <file>        xml file to segment (default: stdin)\n" <<
    "   -o <file>        xml output file (default: stdout)\n" <<
    "   -a <file>        append word set file to defaults\n" <<
    "   -r <file>        replace word set defaults with file contents\n" <<
    "   -s <name>        segment section with name <name>\n" <<
    "   -T               don't leave timestamp info\n" <<
    "   -t               txt2txt mode\n"
    "   -x               txt2xml mode\n\n"
    "eg. " << _INSTALLED_NAME_ << " -i input.xml -a dico -s content > result.xml\n" <<
    "    " << _INSTALLED_NAME_ << " -t < in.txt > out.txt \n" << 
    "    " << _INSTALLED_NAME_ << " -x < in.txt > out.xml \n\n" << 
    "A wordset file contains three sections listing: 2 letter words that can be\n" <<
    "found at the end of a sentence, and 3 and 4 letter accepted abreviations.\n" <<
    "The wordset file contains 1 word per line and three sections enclosed with\n" <<
    "the following tags:\n\n" << 
    "   <2CHAR></2CHAR> enclosing the list of two-letter words\n" <<
    "   <3CHAR></3CHAR> enclosing the list of three-letter words\n" <<
    "   <4CHAR></4CHAR> enclosing the list of four-letter words\n"
    "-----------------------------------------------------------------------------\n";
} 

/* 2006/12/16 */
int main (int argc, char * const argv[]) {
  setlocale(LC_CTYPE, "");

  seg = new StreamSegmenter();
  xmlInterface = new XMLInterface();
  bool describe = false;
  verbose = false;
  stamp = true;
  bool ignore_default_dict = false;
  char* inputfile = NULL;
  char* outputfile = NULL;
  char* batchpath = NULL;
  affectedSections = string("");

  int mode = _XML2XMLMODE;

  int c;
  extern char *optarg;
  while ((c = getopt (argc, argv, "i:o:b:hvVa:r:s:dxtT")) != -1)
    switch(c)
      {
      case 'i':
        inputfile = optarg;
        break;
      case 'o':
        outputfile = optarg;
        break;
      case 'b':
        batchpath = optarg;
        // TODO
        //cerr << "batch (still) unsupported" << endl;
        //return 0;
        break;
      case 'h':
        usage();
        return 0;
        break;
      case 'v':
        verbose = true;
        seg->turnVerboseOn();
        xmlInterface->setVerbose(true);
        break;
      case 'V':
        version();
        return 0;
        break;
      case 'a':
        seg->loadWordSetsFormData(optarg);
        break;
      case 'r':
        ignore_default_dict = true;
        seg->loadWordSetsFormData(optarg);
        break;
      case 'd':
        describe = true;
        break;
      case 's':
        affectedSections.append(optarg);
        affectedSections.append("|");
        break;
      case 'x':
        mode = _TXT2XMLMODE;
        break;
      case 't':
        mode = _TXT2TXTMODE;
        break;
      case 'T':
        stamp = false;
        break;
      default:
        cerr << "default\n";
        usage();
        return 1;
      }


  if (!ignore_default_dict) {
    seg->insertToSet2(dd_array2,dd_array2_size);
    seg->insertToSet3(dd_array3,dd_array3_size);
    seg->insertToSet4(dd_array4,dd_array4_size);
  }

  if (describe) { 
    seg->describe();
    return 0;
  }

  if (batchpath == NULL)
    handleFile(inputfile,outputfile,mode);
  else {
    DIR *dp;
    struct dirent *ep;
    int howmany = 0; // TESTING // J'ai une limite de 250, apres cela
    // tous les parses donnent NULL, meme si
    // - je cree une nouvelle instance de parser
    // - j'appelle parser->resetDocuemntPool
    // je delete et cree une nouvelle XMLInterface!!
    
    dp = opendir (batchpath);
    if (dp != NULL) {
      while (ep = readdir (dp)) {
        if ((ep->d_name)[0] != '.') {

          // TESTING
          //if (howmany++ > 200) {
          //  delete xmlInterface;
          //  xmlInterface = new XMLInterface();
          //}
          // END TESTING

          string thefile(ep->d_name);
          cerr << thefile << endl;
          if (batchpath[strlen(batchpath)-1] != '/')
            thefile.insert(0,"/");
          thefile.insert(0,batchpath);
          if (verbose) cerr << "\n" << _PREFIX_ << "File : " << thefile << endl;
          handleFile(strdup(thefile.c_str()),strdup(thefile.c_str()),mode);
        }
      }
      (void) closedir (dp);
    }
    else
      perror (_PREFIX_ "ERROR Couldn't open the directory");
  }

  delete xmlInterface;
  delete seg;
  return 0;
}

// 2006/12/16
void handleFile(char* filein, char* fileout, int mode)
{
  if (mode==_TXT2TXTMODE) {
    int result;
    if (filein == NULL) {
      if (fileout == NULL) result = seg->segmentStream(cin,cout);
      else {
        ofstream* fout = new ofstream(fileout);
        result = seg->segmentStream(cin,*fout);
        fout->close();
      }
    } else {
      ifstream* fin = new ifstream(filein);
      ofstream* fout = new ofstream(fileout);
      result = seg->segmentStream(*fin,*fout);
      fin->close();
      fout->close();
    } 
    // BROKEN, result is false 2006/11/07
    //if (verbose) 
    //  cerr << "> Segmented in " << result << " sentences." << endl;
  } 
  else if (mode==_TXT2XMLMODE) {

    DOMDocument* out = xmlInterface->createDocument("document");
    DOMElement* root = out->getDocumentElement();
    if (filein != NULL)
      root->setAttribute(XMLString::transcode("filename"),
                         XMLString::transcode(filein));
    DOMElement* contents = out->createElement(XMLString::transcode("content"));
    DOMElement* body = out->createElement(XMLString::transcode("body"));
    DOMElement* section = out->createElement(XMLString::transcode("section"));
    section->setAttribute(XMLString::transcode("analyze"),
                          XMLString::transcode("yes"));
    DOMText* text = 
      out->createTextNode(XMLString::transcode(getFileContents(filein).c_str()));
    section->appendChild(text);
    body->appendChild(section);
    contents->appendChild(body);
    root->appendChild(contents);
    handleDocument(out,fileout);
  } 
  else if  (mode==_XML2XMLMODE) {
    handleDocument(xmlInterface->parse(filein),fileout);
  }
}

// 2006/11/07
void handleDocument(DOMDocument* document, char* outputfile)
{
  if (document == NULL) {
    cerr << _PREFIX_ << "WARNING null XML Document\n";
    return;
  }
  DOMElement* docElement = NULL;
  docElement = document->getDocumentElement();

  if (docElement == NULL) {
    cerr << _PREFIX_ << "WARNING null XML Document Element\n";
    return;
  }


  DOMNodeList* sections = docElement->getElementsByTagName(XMLString::transcode("section"));
  int sCount = 0;
  int paragraphID = 1;

  for (unsigned int i = 0; i < sections->getLength(); i++) {
    int sectID = i+1;
    if (verbose) cerr << _PREFIX_ << "Section " << i;
    DOMElement* aSect = NULL;
    aSect = (DOMElement*)sections->item(i);
    string sectName = XMLString::transcode(((DOMElement*)aSect)->getAttribute(XMLString::transcode("name")));
    string analyze =
      XMLString::transcode(((DOMElement*)aSect)->getAttribute(XMLString::transcode("analyze")));
    if (verbose) cerr << " ['" << sectName << "'";
    // Ignore non affected sections 
    if ( ( analyze == "yes" ) ||
         ( sectName.length() == 0 ) ||
         ( affectedSections.find(sectName + "|") != string::npos )) {      
      
      if (verbose) cerr << " analyze=yes ";
      // Deal with unnamed and affected sections

      // create a stream
      aSect->normalize();
      stringstream text(XMLString::transcode(aSect->getTextContent()));

      if (verbose) {
        string temp(XMLString::transcode(aSect->getTextContent()));
        cerr << temp.length() << " charcters]\n" << _PREFIX_ << "           ";
      }

      aSect->removeChild(aSect->getFirstChild());

      vector<vector<string> > result;
      result = seg->segmentInVectors(text);

      for(vector<vector<string> >::iterator itp = result.begin(); 
          itp != result.end(); 
          itp++) {
        stringstream parID;
        parID << _ID_PREFIX_SECTION << sectID << _ID_PREFIX_PARAGRAPH << paragraphID++;
        sCount += addSegmentedParagraphToSection(*itp,aSect,parID.str().c_str());
      }
   
      if (verbose) cerr << endl;
    } else {
      if (verbose) cerr << " analyze=no]" << endl;
    }
  }

  if (stamp) stampDocument(docElement);

  /* SERIALIZE XML DOCUMENT */
  if (outputfile == NULL) xmlInterface->serializeTo(document);
  else xmlInterface->serializeTo(document,outputfile);

  if (verbose) cerr << _PREFIX_ << "Segmented in " << sCount << " sentences." << endl;
}

// 2006/11/07
string getFileContents(char* filename)
{
  istream* instream;
  ifstream* fin = NULL;
  if (filename == NULL) {
    instream = &cin;
  } else {
    fin = new ifstream(filename);
    instream = fin;
  }
  stringstream contents;
  string line;
  while (!getline(*instream,line).eof()) {
    contents << line.c_str() << '\n';
  }
  if (fin != NULL) fin->close();
  return contents.str();
}

// 2006/12/16
void stampDocument(DOMElement* root) {
  DOMElement* meta = NULL;
  DOMElement* macastamps = NULL;
  DOMElement* stamp = NULL;

  stamp = (root->getOwnerDocument())->createElement(XMLString::transcode("maca_stamp"));
  stamp->setAttribute(XMLString::transcode("module"),
                      XMLString::transcode(_INSTALLED_NAME_));
  stamp->setAttribute(XMLString::transcode("version"),
                      XMLString::transcode(_VERSION_));
  stamp->setAttribute(XMLString::transcode("timestamp"),
                      XMLString::transcode(getTimestamp().c_str()));

  DOMNodeList* metaList = root->getElementsByTagName(XMLString::transcode("meta"));
  if (metaList->getLength() == 0) { // NO meta Element
    meta = (root->getOwnerDocument())->createElement(XMLString::transcode("meta"));
    macastamps =
      (root->getOwnerDocument())->createElement(XMLString::transcode("maca_stamps"));
    meta->appendChild(macastamps);
    root->insertBefore(meta,root->getFirstChild());
  } else { // meta Element
    meta = (DOMElement*)metaList->item(0);
    DOMNodeList* macastampsList = 
      meta->getElementsByTagName(XMLString::transcode("maca_stamps"));
    if (macastampsList->getLength() == 0) { // NO macastamps Element
      macastamps =
        (root->getOwnerDocument())->createElement(XMLString::transcode("maca_stamps"));
      meta->appendChild(macastamps);
    } else { // macastamps Element
      macastamps = (DOMElement*)macastampsList->item(0);
    }
  }
  macastamps->appendChild(stamp);
}

string getTimestamp() {
  time_t rawtime;
  time(&rawtime);
  string timeStr(ctime(&rawtime));
  return timeStr.substr(0,timeStr.find('\n'));
}

int addSegmentedParagraphToSection(vector<string> par, DOMElement* sect, const char* pid){
  DOMElement* aPar = NULL;
  int sid = 1;
  aPar =
  (sect->getOwnerDocument())->createElement(XMLString::transcode("paragraph"));

  aPar->setAttribute(XMLString::transcode("id"),
                     XMLString::transcode(pid));

  if ( aPar != NULL ) {
    for (vector<string>::iterator it = par.begin(); it != par.end(); it++) {
      if (verbose) cerr << "s";
      DOMElement* aSent = NULL;
      DOMElement* aSentText = NULL;
      aSent = (sect->getOwnerDocument())->createElement(XMLString::transcode("sentence"));
      aSentText = (sect->getOwnerDocument())->createElement(XMLString::transcode("text"));
      if ( (aSent != NULL) && (aSentText != NULL) ) {
        aSentText->setTextContent(XMLString::transcode((*it).c_str()));
        aSent->appendChild(aSentText);
        aPar->appendChild(aSent);
        stringstream sentId;
        sentId << pid << _ID_PREFIX_SENTENCE << sid;
        aSent->setAttribute(XMLString::transcode("id"),
                            XMLString::transcode(sentId.str().c_str()));
        sid++;
      }
    }
    sect->appendChild(aPar);
  }
  if (verbose) cerr << " ";
  return sid-1;
}


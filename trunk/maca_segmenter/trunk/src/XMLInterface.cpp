/* Copyright (C) Alejandro Acosta 2005/2006 
 * Distributed under GPL License. See COPYING.
 *
 * AA 2006/11/06  
 * MODIFIED 2006/12/20
 */

#include <fstream>

#include "XMLInterface.hh"

#include "Version.h"

#ifdef _INSTALLED_NAME_
#define _PREFIX_ "[" _INSTALLED_NAME_ "] "
#else
#define _PREFIX_ ""
#endif

XERCES_CPP_NAMESPACE_USE
using namespace std;


// THIS SHOULD BE REPLACED AS SOON AS STDIN PARSE WORKS
void xercesReadStdinProblemWorkaround(char *tmpfile)
{
  ofstream out(tmpfile);
  string line;
  while (!getline(cin,line).eof())
    out << line << "\n";
}


XMLInterface::XMLInterface()
{
  parser = NULL;
  serializer = NULL;
  verbose = false;

  if ( initialize() ) {
    // PARSER
    // NB. ErrorHandler ?
    // cerr << "Starting XML Interface" << endl; // DEBUG
    parser = createParser();
    serializer = createSerializer();
  }
}


XMLInterface::~XMLInterface()
{
  delete parser;
  delete serializer;
  terminate();
}


bool XMLInterface::initialize() {
  try {
    XMLPlatformUtils::Initialize();
  } catch (const XMLException& toCatch) {
    cerr << _PREFIX_ << "ERROR XML Xerces-c Initialization" << endl;
    return false;
  }
  return true;
}

bool XMLInterface::terminate(){
  // cerr << "> Terminanting XMLInterface" << endl; // DEBUG
  try {
    XMLPlatformUtils::Terminate();
  } catch (const XMLException& toCatch) {
    cerr << _PREFIX_ << "ERROR XML Xerces-c Termination" << endl;
    return false;
  }
  return true;
}

DOMDocument* XMLInterface::parse(char* file)
{
  DOMDocument* out = NULL;
  try {
    // 2006/11/08
    //parser->resetDocumentPool(); //??
  } catch (...) {
    cerr << _PREFIX_ << "ERROR XML Reseting parser" << endl;
  }
  try {
    // STDIN PARSE WORKAROUND
    if ( file == NULL ) {
      if (verbose)
        cerr << _PREFIX_ << "Parsing stdin" << endl;
      char* tmpFile = "/tmp/xerces.stdin.tmp.xml";
      xercesReadStdinProblemWorkaround(tmpFile);
      out = parser->parseURI(tmpFile);
      remove(tmpFile);
    } else {
      if (verbose)
        cerr << _PREFIX_ << "Parsing XML file '" << file << "'" << endl;
      out = parser->parseURI(file);
    }   
  } catch (...) {
    cerr << _PREFIX_ << "WARNING XML error parsing: '" << file << "'" << endl;
  }
  return out;
}

void XMLInterface::addSchema(char* path) {
  //TODO
//   if (path != NULL) {
//     if ( !parser->getDoSchema() ) {
//       parser->setValidationScheme(XercesDOMParser::Val_Always);
//       parser->setDoSchema(true);
//       parser->setDoNamespaces(true);
//     } else {
//       parser->setExternalSchemaLocation(path);
//     }
//   } else {
//     cerr << "[WAR] XML schema not found: '" << path << "'" << endl;
//   }
}

DOMDocument* XMLInterface::createDocument(char* elementNodeName)
{
  DOMDocument* out = NULL;
  DOMImplementation* impl =  
    DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("Core"));
  if (impl != NULL) {
    try {
      // (Namespace, root element name, DTD)
      out = impl->createDocument(0,XMLString::transcode(elementNodeName),0);
      // WAR: Experimental XERCES-C function, might break
      out->setStandalone(true);
    } catch (const OutOfMemoryException&) {
      cerr << _PREFIX_ << "ERROR Out of memory creating DOM Document" << endl;
    } catch (const DOMException& toCatch) {
      char* message = XMLString::transcode(toCatch.msg);
      cerr << _PREFIX_ << "ERROR DOM Exception : \n" << message << "\n";
      XMLString::release(&message);
    } catch (...) {
      cerr << _PREFIX_ << "ERROR Unexpected error creating DOM Document" << endl;
    }
  }
  return out;
}

bool XMLInterface::serializeTo(DOMDocument* doc,char* file)
{
  try {
    string thestdout = "<STDOUT>";
    XMLFormatTarget* myFormTarget;

    if ( thestdout.find(file,0) != string::npos  ) {
      myFormTarget = new StdOutFormatTarget();
    } else {
      myFormTarget = new LocalFileFormatTarget(XMLString::transcode(file));
      if (verbose)
        cerr << _PREFIX_ << "Serializing to '" << file << "'" << endl;
    }
    
    serializer->writeNode(myFormTarget,*doc);

  } catch (const XMLException& toCatch) {
    char* message = XMLString::transcode(toCatch.getMessage());
    cerr << _PREFIX_ << "WARNING XML Exception : \n"
         << message << "\n";
    XMLString::release(&message);
  } catch (const DOMException& toCatch) {
    char* message = XMLString::transcode(toCatch.msg);
    cerr << _PREFIX_ << "WARNING DOM Exception : \n"
         << message << "\n";
    XMLString::release(&message);
  } catch (...) {
    cerr << _PREFIX_ << "WARNING Unexpected error serializing '" << file << "'"<< endl;
  }
}

DOMWriter* XMLInterface::createSerializer()
{
  DOMWriter * out = NULL;
  XMLCh tempStr[100];
  XMLString::transcode("LS", tempStr, 99);
  DOMImplementation *impl = 
    DOMImplementationRegistry::getDOMImplementation(tempStr);
  out = ((DOMImplementationLS*)impl)->createDOMWriter();

  // Properties
  if (out->canSetFeature(XMLUni::fgDOMWRTFormatPrettyPrint, true))
    out->setFeature(XMLUni::fgDOMWRTFormatPrettyPrint, true);
  // ...

  return out;
}

DOMBuilder* XMLInterface::createParser()
{
  DOMBuilder* out = NULL;
  XMLCh tempStr[100];
  XMLString::transcode("LS", tempStr, 99);
  DOMImplementation *impl = 
    DOMImplementationRegistry::getDOMImplementation(tempStr);
  out =
  ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS,
  0);
  out->setErrorHandler(this);
  // Properties: Validation, Schema ...
  // cf. http://xml.apache.org/xerces-c/program-dom.html#DOMBuilderFeatures
  //if (parser->canSetFeature(XMLUni::fgDOMValidation, true))
  //          parser->setFeature(XMLUni::fgDOMValidation, true);
  // ...

  return out;
}

// Implementing DOMErrorHandler
bool XMLInterface::handleError(const DOMError &domError)
{
  char* message = XMLString::transcode(domError.getMessage());
  cerr << _PREFIX_ << "ERROR parsing XML: " << message << endl;
}



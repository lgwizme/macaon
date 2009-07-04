/* Copyright (C) Alejandro Acosta 2005/2006 
 * Distributed under GPL License. See COPYING. 
 *
 * StreamSegmenter.cpp
 * segmenter
 *  
 * AA 2005/04/25
 * MODIFIED 2007/10/24 : guillemets en fin de phrase
 *          2006/12/17 */

#include "StreamSegmenter.h"
#include "Version.h"

#ifdef _INSTALLED_NAME_
#define _PREFIX_ "[" _INSTALLED_NAME_ "] "
#else
#define _PREFIX_ ""
#endif

using namespace std;

bool StreamSegmenter::isBoundary(const string& s, string::size_type offset)
{
  try {
    if (offset == 0) {
      return true;
    }
    if ( offset < s.length() ) {
      if ( (offset + 1) < s.length() ) {
		if (s.at(offset+1) == '\n') return true;
		else if (s.at(offset+1) != ' ') return false;
		else if (((offset -1) > 0) && ((offset -1) != string::npos)) {
		  if (s.at(offset-1) == ('"' || ")" || '>' || "]")) return true;
		  else {
            string lastword = lastWord(s,offset);
            int count;
            if ( lastword.length() == 1 ) {
              if (isUpper(lastword.at(0))) return false;
              else if (lastword.at(0) == 'y') return true;
              else if (lastword.at(0) == 'a') return true;
              else if (lastword.at(0) == 'p') {
                if ((offset + 2) < s.length()) {
                  if (isdigit(s.at(offset+2))) return false; // p. 23
                  else return true;
                } else return true; // 234 p. (pages)
              }
              else if (isdigit(lastword.at(0))) return true;
              else return false;
            } else if ( lastword.length() == 2 ) {
              if (verbose) cerr << "('" << lastword << "'";
              if ((count = set2.count(lastword)) > 0) {
                if (verbose) cerr << " in voc. YES) ";
                return true;	
              }
              else if (isAllUpper(lastword)) {
                if (verbose) cerr << " allUpper YES) ";
                return true;
              }
              else if (isdigit(lastword.at(0)) && isdigit(lastword.at(1))) {
                if (verbose) cerr << " bothDigit YES) ";
                return true;
              }
              else {
                if (verbose) if (isdigit(lastword.at(0))) cerr << " firstdigit";
                if (verbose) if (isdigit(lastword.at(1))) cerr << " seconddigit";
                if (verbose) cerr << " NO) ";
                return false;
              }
            } else if ( lastword.length() == 3 ) {
              if ((count = set3.count(lastword)) > 0) return false;
              else return true;
            } else if ( lastword.length() == 4) {
              if (set4.count(lastword) > 0) return false;
              else return true;
            } else return true;
		  }
		}
      } else return true;
    }
    return false; 
  } catch (...) {
    cerr << _PREFIX_ << "WARNING Unexpected boundary found, report bug." << endl;
    return true;
  }
}


string StreamSegmenter::lastWord(const string&s, int pos) {
  string out;
  for (int start = prevCharPos(s,pos);
		 (start > -1) && (s.at(start) != ' ') 
			&& (s.at(start) != '(') 
			&& (s.at(start) != ')') 
			&& (s.at(start) != '>') 
			&& (s.at(start) != '<')
			&& (s.at(start) != '"') 
			&& (s.at(start) != '[') 
			&& (s.at(start) != ']') 
			&& (s.at(start) != '.');
		 start--)
	 out.insert(out.begin(),s.at(start));
  return out;
}


bool StreamSegmenter::isUpper(int lechar) {
  if (isupper(lechar)) return true;
  else {
	 switch (lechar) 
		{
		case '\300': case '\301': case '\302': case '\304': case '\310':
		case '\311': case '\312': case '\316': case '\317': case '\315':
		case '\323': case '\324': case '\326': case '\334': case '\333':
		case '\332': case '\307': return true;
		default : return false; 
		}
  }
  return false;
}


bool StreamSegmenter::isAllUpper(const std::string& s){
  for (string::size_type i = 0; i < s.length(); i++)
	 if (!isUpper(s.at(i))) return false;
  return true;
}

bool StreamSegmenter::hasDigit(const std::string& s) {
  for (string::size_type i = 0; i < s.length(); i++)
	 if (!isdigit(s.at(i))) return true;
  return false;
}


bool StreamSegmenter::isLower(int lechar) {
  if (islower(lechar)) return true;
  else {
	 switch (lechar) 
		{
		case '\340': case '\341': case '\342': case '\346': case '\347': 
		case '\350': case '\351': case '\352': case '\355': case '\356': 
		case '\357': case '\363': case '\364': case '\366': case '\372': 
		case '\373': case '\374': return true;
		default : return false; 
		}
  }
  return false;
}

int StreamSegmenter::nextCharPos(const string& s, string::size_type pos)
{
  if (pos == (s.length() - 1)) return -1;
  int offset = 1;
  while (s.at(pos + offset) == '<') {
	 for(offset++ ;s.at(pos + offset) != '>';offset++){
		if ((pos + offset) == (s.length() - 1)) {
		  cerr << _PREFIX_ << "WARNING: Couldn't find end of tag.";
		  return -1;
		}
	 }
	 if ((pos + offset) == (s.length() - 1)) return -1;
	 offset++;
  }
  return pos + offset;
}

int StreamSegmenter::prevCharPos(const string& s, string::size_type pos)
{
  if (pos == 0) return -1;
  int offset = 1;
  while (s.at(pos - offset) == '>') {
	 for(offset++ ;s.at(pos - offset) != '<';offset++){
		if ((pos - offset) == 0) {
		  cerr << _PREFIX_ << "WARNING: Couldn't find beginning of tag.";
		  return -1;
		}
	 }
	 if ((pos - offset) == 0) return -1;
	 offset++;
  }
  return pos - offset;
}

// check if the string is empty (we don't want empty sentences)
bool StreamSegmenter::isEmpty(const std::string& s){
  if (s.size() < 1) return true;
  for ( string::size_type i = 0; i < s.size(); i++ ) {
	 if ( (s.at(i) != ' ') && (s.at(i) != '\n') && (s.at(i) != '\t'))
		return false;
  }
  return true;
}


std::vector<string> StreamSegmenter::parseLine()
{
  string boundaryChars(_SS_LINE_BOUNDARY_);
  string postBoundaryNoQuote(_SS_LINE_BOUNDARY_);
  string postBoundaryWithQuote(_SS_LINE_BOUNDARY_);
  boundaryChars.append("\"");
  postBoundaryNoQuote.append(" ");
  postBoundaryWithQuote.append(" \"");
  string* postBoundaryChars = &postBoundaryNoQuote;
  bool inQuote = false;
  vector<string> out;
  string::size_type pos = 0;
  while ((pos = line.find_first_of(boundaryChars,pos)) != string::npos) {
    if (line.at(pos) == '"') {
      inQuote = inQuote ? false : true ;
      if (inQuote) postBoundaryChars = &postBoundaryWithQuote;
      else postBoundaryChars = &postBoundaryNoQuote;
      pos++;
    } else if (isBoundary(line,pos)) {
      if (verbose)
        cerr << "[" << line.at(pos) << ":" << pos << "/" << line.length() << "]"; 
      while (((pos+1) != string::npos) && 
             ((pos+1) < (line.length()-1)) &&
             (postBoundaryChars->find(line.at(pos+1)) != string::npos)) {
        // advance as long as boundary is followed by boundary chars or blanks
        if (verbose)
          cerr << "[" << line.at(pos) << ":" << pos << "/" << line.length() << "]"; 
        pos++;
        
      }
      if (verbose) cerr << endl;
      out.push_back(trim(line.substr(0,pos+1)));
      if (inQuote) { // if we found a boundary, quotes are (forced) closed if open
        inQuote = false;
        postBoundaryChars = &postBoundaryNoQuote;
      }
      line = line.substr(pos + 1, line.length() - 1);
      pos = 0;
	 } else {
		pos++;
	 }
  }
  if (line.length() > 0) out.push_back(line);
  line = "";
  return out;
}

string StreamSegmenter::trim(string s)
{
  string::size_type end = (s.length()-1);
  while (s.at(end) == ' ') end--;
  return s.substr(0,++end);
}

int StreamSegmenter::segmentStream(std::istream& in, std::ostream& out)
{
  int count = 0;
  vector<string> lineRes;
  vector<string>::iterator it;

  
  while (getline(in,line)) {
	 // cout << lineCount << endl;
	 count++;
	 lineRes = parseLine();
	 if (lineRes.size() > 0) out << paragraphOpening << endl;
	 for(it = lineRes.begin(); it != lineRes.end(); it++) {
		if ( !isEmpty(*it) )
		  out << sentenceOpening << *it << sentenceClosure << endl;
	 }
	 if (lineRes.size() > 0) out << paragraphClosure << endl;
  }
  
  return count;
}

vector<vector<string> > StreamSegmenter::segmentInVectors(std::istream& in){  
  vector<vector<string> > out;
  vector<string> lineRes;

  while (getline(in,line)) {
	 lineRes = parseLine();
	 if (lineRes.size() > 0) out.push_back(lineRes);
  }

  return out;
}

void  StreamSegmenter::loadWordSetsFormData(char* file) {
  ifstream in;
  in.open(file);
  string dicoline;
  if (verbose) cerr << _PREFIX_ << "reading file '" << file << "'\n";
  while (getline(in,dicoline)) {
    if (dicoline.find( "<2CHAR>" ) != string::npos ) {
      while (getline(in,dicoline)) {
	if (dicoline.find( "</2CHAR>" ) != string::npos ) break;
	else  if (dicoline.length() == 2) set2.insert(dicoline);
      }
    } else if (dicoline.find("<3CHAR>") == 0) {
      while (getline(in,dicoline)) {
	if (dicoline.find( "</3CHAR>" ) != string::npos ) break;
	else if (dicoline.length() == 3) set3.insert(dicoline);
      }
    } else if (dicoline.find("<4CHAR>") == 0) {
      while (getline(in,dicoline)) {
	if (dicoline.find( "</4CHAR>" ) != string::npos ) break;
	else if (dicoline.length() == 4) set4.insert(dicoline);
      }      
    }
  }
  if (verbose) cerr << _PREFIX_ << "read file '" << file << "'\n";
}


void StreamSegmenter::insertToSet2(const string dset[], int size){
  for(int i = 0; i < size;i++)
	 set2.insert(dset[i]);
  //  cout << "size2[]=" << sizeof dset/sizeof *dset << endl;
}

void StreamSegmenter::insertToSet3(const string dset[], int size){
  for(int i = 0; i < size;i++)
	 set3.insert(dset[i]);
  //  cout << "size3[]=" << sizeof dset/sizeof *dset << endl;
}

void StreamSegmenter::insertToSet4(const string dset[], int size){
  for(int i = 0; i < size;i++)
	 set4.insert(dset[i]);
  //  cout << "size4[]=" << sizeof dset/sizeof *dset << endl;
}


string ss_escapeNL(string x){
  string::size_type i;
  while ((i = x.find('\n')) != string::npos) {
    x.replace(i,1,"\\n");
  }
  return x;
}


void StreamSegmenter::describe() {
	  std::set<std::string>::iterator it;
	  std::cout << "<2CHAR>\n";
	  for (it = set2.begin(); it != set2.end(); it++) {
		 std::cout << *it; 
		 if (it != --set2.end()) std::cout << "\n";
	  }
	  std::cout << "\n</2CHAR>\n<3CHAR>\n";
	  for (it = set3.begin(); it != set3.end(); it++) {
		 std::cout << *it;
		 if (it != --set3.end()) std::cout << "\n";
	  }
	  std::cout << "\n</3CHAR>\n<4CHAR>\n";
	  for (it = set4.begin(); it != set4.end(); it++) {
		 std::cout << *it;
		 if (it != --set4.end()) std::cout << "\n";
	  }
	  std::cout << "\n</4CHAR>" << std::endl; 
}


/* Copyright (C) Alejandro Acosta 2005/2006 
 * Distributed under GPL License. See COPYING. 
 *
 * StreamSegmenter.h
 * segmenter
 * 
 * AA 2005/11/22.
 * MODIFIED 2006/11/02 */

#ifndef _STREAMSEGMENTER_
#define _STREAMSEGMENTER_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <ctype.h>

// 3 reject sentence: Réf réf Dép Mun Nat
// 4 reject sentence: Arch Bibl

#define _SS_LINE_BOUNDARY_ ".?!"

class StreamSegmenter {
  bool verbose;
  std::string line;
  std::string sentenceOpening;
  std::string sentenceClosure;
  std::string paragraphOpening;
  std::string paragraphClosure;
  std::set<std::string> set2;
  std::set<std::string> set3;
  std::set<std::string> set4;

  int prevCharPos(const std::string& s, std::string::size_type pos);
  int nextCharPos(const std::string& s, std::string::size_type pos);
  std::string lastWord(const std::string&s, int pos);
  bool isLower(int lechar);
  bool isUpper(int lechar);
  bool isAllUpper(const std::string& s);
  bool hasDigit(const std::string& s);
  bool isBoundary(const std::string& s, std::string::size_type offset);
  std::string trim(std::string s);
  bool isEmpty(const std::string& s);
  std::vector<std::string> parseLine();
 
 public: 
 StreamSegmenter(const std::string& open = "  <sentence>",
                 const std::string& close = "</sentence>",
                 const std::string& popen = "<paragraph>",
                 const std::string& pclose = "</paragraph>") : verbose(false), sentenceOpening(open), sentenceClosure(close), paragraphOpening(popen), paragraphClosure(pclose) { }

  void describe();
  void turnVerboseOn() { verbose = true; }

  void setSentenceTag(const std::string& s) {
    setSentenceOpening("<" + s + ">");
    setSentenceClosure("</" + s + ">");
  }
  void setParagraphTag(const std::string& s) {
    setParagraphOpening("<" + s + ">");
    setParagraphClosure("</" + s + ">");
  }
  void setSentenceOpening(const std::string& s) {
    sentenceOpening = s;
  }
  void setSentenceClosure(const std::string& s) {
    sentenceClosure = s;
  }
  void setParagraphOpening(const std::string& s) {
    paragraphOpening = s;
  }
  void setParagraphClosure(const std::string& s) {
    paragraphClosure = s;
  }

  int segmentStream(std::istream& in, std::ostream& out);
  std::vector<std::vector<std::string> > segmentInVectors(std::istream& in);
  void loadWordSetsFormData(char*);

  void insertToSet2(const std::string dset[], int size);
  void insertToSet3(const std::string dset[], int size);
  void insertToSet4(const std::string dset[], int size);
  int sizeSet2() { return set2.size(); }
  int sizeSet3() { return set3.size(); }
  int sizeSet4() { return set4.size(); }

};

#endif // _STREAMSEGMENTER_

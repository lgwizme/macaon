/* Copyright (C) Alejandro Acosta 2005/2006 
 * Distributed under GPL License. See COPYING.
 *
 * AA 2006/11/06  
 * MODIFIED 2006/11/07
 * A Xerces-C I/O wrapper
 */

#ifndef _XML_INTERFACE
#define _XML_INTERFACE

#include <iostream>
#include <string>

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

XERCES_CPP_NAMESPACE_USE

class XMLInterface : public DOMErrorHandler
{
private:
  DOMBuilder* parser;
  DOMWriter* serializer;
  bool verbose;
 
protected:
  XMLInterface(const XMLInterface&); // Blocks "pass by value"
public:
  XMLInterface();
  virtual ~XMLInterface();

  void addSchema(char* path);
  void setVerbose(bool v) { verbose = v; }

  DOMDocument* parse(char* file);
  DOMDocument* createDocument(char* elementNodeName);
  bool serializeTo(DOMDocument* doc,char* file = "<STDOUT>");
  bool handleError(const DOMError &domError);

private:
  bool initialize();
  bool terminate();
  DOMWriter* createSerializer();
  DOMBuilder* createParser();
};

#endif // _XML_INTERFACE

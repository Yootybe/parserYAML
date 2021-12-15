#include "Factories.h"
#include "MyParser.h"
#include "VisitorImp.h"
#include "StreamSource.h"
#include "StreamSink.h"
#include "StringSource.h"
#include "StringSink.h"
#include "DecoratorVisitor.h"
#include "DecoratorSource.h"
#include "DecoratorSink.h"
#include "DecoratorParser.h"

Visitor* makeVisitor(const std::string& type, Sink* sink)
{
    if (type == "logger")
    {
        return new DecoratorVisitor(new VisitorImp(sink));
    }
    return new VisitorImp(sink);
}

Parser* makeParser(const std::string& type, Source* source)
{
    if (type == "logger")
    {
        return new DecoratorParser(new MyParser(source));
    }
    return new MyParser(source);
}

Source* makeSource(const std::string& type)
{
    if (type == "loggerfile")
    {
        return new DecoratorSource(new StreamSource);
    }
    else if (type == "loggerstring")
    {
        return new DecoratorSource(new StringSource);
    }
    else if (type == "file")
    {
        return new StreamSource;
    }
    else if (type == "string")
    {
        return new StringSource;
    }
    return new StringSource;
}

Sink* makeSink(const std::string& type)
{
    if (type == "loggerfile")
    {
        return new DecoratorSink(new StreamSink);
    }
    else if (type == "loggerstring")
    {
        return new DecoratorSink(new StringSink);
    }
    else if (type == "file")
    {
        return new StreamSink;
    }
    else if (type == "string")
    {
        return new StringSink;
    }
    return new StringSink;
    
}
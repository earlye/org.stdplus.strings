#include <org.stdplus/strings/fromString.hpp>

#include <stdexcept>

void testFromString()
{
  if (1.0 != org::stdplus::strings::fromString<double>("1.0") )
    throw std::runtime_error("Expected fromString to work for double");
  if (1.0L != org::stdplus::strings::fromString<long double>("1.0") )
    throw std::runtime_error("Expected fromString to work for long double");
  if (1L != org::stdplus::strings::fromString<long>("1") )
    throw std::runtime_error("Expected fromString to work for long");
  if (1 != org::stdplus::strings::fromString<int>("1") )
    throw std::runtime_error("Expected fromString to work for int");
}

void testStringFromString()
{
  std::string input = "1.0";

  std::string const& output = org::stdplus::strings::fromString<std::string>(input);

  if ( output != input )
    throw std::runtime_error( "Expected fromString to be optimized for std::string" );
}

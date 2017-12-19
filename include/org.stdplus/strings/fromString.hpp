#ifndef he18797e1_a055_48fd_a016_77ae6976a817
#define he18797e1_a055_48fd_a016_77ae6976a817

#include <string>
#include <sstream>
#include <typeinfo>

namespace org
{
  namespace stdplus
  {
    namespace strings
    {
      template<typename TARGET_TYPE> inline TARGET_TYPE fromString( std::string const& value )
      {
        std::stringstream interpret(value);
        TARGET_TYPE result;
        interpret >> result;
        if ( !interpret )
          throw std::bad_cast();
        return result;
      }

      // optimize for std::string, where you can just return a copy of the original value.
      template<> inline std::string fromString<std::string>( std::string const& value )
      { return value; }

    } // namespace strings
  } // namespace stdplus
} // namespace org
#endif

#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) :
  capacity_( capacity ),
  buffer_( std::vector<uint8_t>(capacity) ),
  start_( 0 ),
  end_( 0 ) {}

bool Writer::is_closed() const
{
  // Your code here.
  return {};
}

void Writer::push( string data )
{
  // Your code here.
  (void)data;
  return;
}

void Writer::close()
{
  // Your code here.
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_;
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return {};
}

bool Reader::is_finished() const
{
  // Your code here.
  return {};
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return {};
}

string_view Reader::peek() const
{
  // Your code here.
  return {};
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  (void)len;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return {};
}

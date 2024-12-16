#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) :
  capacity_( capacity ),
  bytes_pushed_( 0 ),
  bytes_popped_( 0 ),
  buffer_( std::vector<uint8_t>(capacity, 0) ),
  start_( 0 ),
  end_( 0 ),
  closed_( false ){}

bool Writer::is_closed() const
{
  return closed_;
}

void Writer::push( string data )
{
  int len = std::min(capacity_, data.length());
  for(int i = 0; i < len; ++i){
    buffer_[end_] = static_cast<uint8_t>(data[i]);
    end_ = (end_ + 1) % buffer_.size();
    capacity_--;
    bytes_pushed_++;
  }
  return;
}

void Writer::close()
{
  closed_ = true;
}

uint64_t Writer::available_capacity() const
{
  return capacity_;
}

uint64_t Writer::bytes_pushed() const
{
  return bytes_pushed_;
}

bool Reader::is_finished() const
{
  return closed_ && bytes_buffered() == 0;
}

uint64_t Reader::bytes_popped() const
{
  return bytes_popped_;
}

string_view Reader::peek() const
{
  int len;
  if (bytes_buffered())
    len = start_ < end_ ? end_ - start_ : buffer_.size() - start_;
  else
    len = 0;
  return std::string_view(reinterpret_cast<const char*>(buffer_.data() + start_), len);
}

void Reader::pop( uint64_t len )
{
  int amt = std::min(len, bytes_buffered());
  start_ = (start_ + amt) % buffer_.size();
  capacity_ += amt;
  bytes_popped_ += amt;
}

uint64_t Reader::bytes_buffered() const
{
  return buffer_.size() - capacity_;
}

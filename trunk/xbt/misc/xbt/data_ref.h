#pragma once

#include <boost/range/iterator_range.hpp>
#include <cstdlib>
#include <cstring>
#include <string>

template <class T, class U>
class data_ref_base : public boost::iterator_range<T>
{
public:
	data_ref_base()
	{
	}

	template<class V>
  data_ref_base(const V& v)
	{
    if (v.end() != v.begin())
		  assign(&*v.begin(), v.end() - v.begin() + &*v.begin());
	}

	template<class V>
  data_ref_base(V& v)
	{
    if (v.end() != v.begin())
		  assign(&*v.begin(), v.end() - v.begin() + &*v.begin());
	}

  explicit data_ref_base(const char* v)
  {
    assign(v, strlen(v));
  }

  explicit data_ref_base(char* v)
  {
    assign(v, strlen(v));
  }

	data_ref_base(U begin, U end)
	{
		assign(begin, end);
	}

	data_ref_base(U begin, size_t size)
	{
		assign(begin, size);
	}

	void assign(U begin, U end)
	{
    static_cast<iterator_range_&>(*this) = iterator_range_(reinterpret_cast<T>(begin), reinterpret_cast<T>(end));
	}
	
	void assign(U begin, size_t size)
	{
    assign(begin, reinterpret_cast<T>(begin) + size);
	}
	
	T data() const
  {
    return begin();
  }

	template<class V>
	data_ref_base find(V v) const
	{
		data_ref_base t = *this;
		while (!t.empty() && *t != v)
			t++;
		return t;
	}

	long long i() const
	{
		return atoll(reinterpret_cast<const char*>(data()));
	}

	std::string string() const
	{
		return std::string(reinterpret_cast<const char*>(data()), size());
	}

	data_ref_base sub_range(size_t o, size_t s)
	{
		return data_ref_base(begin() + o, s);
	}
};

typedef data_ref_base<const unsigned char*, const void*> data_ref;
typedef data_ref_base<unsigned char*, void*> mutable_data_ref;
typedef data_ref_base<const char*, const void*> str_ref;
typedef data_ref_base<char*, void*> mutable_str_ref;

inline size_t memcpy(void* d, data_ref s)
{
  memcpy(d, s.data(), s.size());
  return s.size();
}

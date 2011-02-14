#pragma once

#include <boost/foreach.hpp>
#include <boost/format.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/utility.hpp>
#include <cassert>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <signal.h>
#include <sstream>
#include <string>
#include <vector>

#ifdef WIN32
#define FD_SETSIZE 1024
#define NOMINMAX

#define atoll _atoi64
#else
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <cstdio>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#endif

typedef unsigned char byte;

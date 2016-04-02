# Extended BitTorrent Client and Tracker (xbt, xbtt)
## High-performance BitTorrent Tracker

Extended BitTorrent Client and Tracker. High-performance software for this peer to peer file distribution protocol. A Windows client written in C++. A tracker written in C++, using MySQL as secondary storage.

## Installing under Linux

Use the following commands to install the dependencies on Debian. The g++ version should be at least 4.7.

```apt-get install cmake g++ libboost-dev libmysqlclient-dev make subversion zlib1g-dev```

Use the following commands to install some of the dependencies on CentOS, Fedora Core and Red Hat. The g++ version should be at least 4.7.

```yum install boost-devel cmake gcc-c++ mysql-devel subversion```

Enter the following commands in a terminal. Be patient while g++ is running, it'll take a few minutes.

```
git clone https://github.com/abixalmon/xbt
cd xbt/Tracker
./make.sh
cp xbt_tracker.conf.default xbt_tracker.conf
```

Forked from https://code.google.com/archive/p/xbt/


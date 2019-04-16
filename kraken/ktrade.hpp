#ifndef _KRAKEN_KTRADE_HPP_
#define _KRAKEN_KTRADE_HPP_

#include <string>
#include <sstream>
#include "../libjson/libjson.h"

//------------------------------------------------------------------------------

namespace Kraken { 

//------------------------------------------------------------------------------
// deals with recent trade data:
struct KTrade {

   enum Otype_t { MARKET='m', LIMIT='l' };
   enum Order_t { BUY='b', SELL='s' };

   double price, volume;
   time_t time;
   Otype_t otype;
   Order_t order;
   std::string misc;

   // default ctor
   KTrade() :price(0), volume(0), time(0),
	     otype(KTrade::MARKET), 
	     order(KTrade::BUY) { }

   // construct from a JSONNode 
   KTrade(JSONNode node);
};

// deals with recent trade data:
struct KOHLC {

   time_t time;
   double openprice, highprice, lowprice, closeprice, vwap, volume, count;

   // default ctor
   KOHLC() :time(0), openprice(0), highprice(0), 
        lowprice(0), vwap(0), volume(0), count(0) { }

   // construct from a JSONNode 
   KOHLC(JSONNode node);
};
//<time>, <open>, <high>, <low>, <close>, <vwap>, <volume>, <count>

//------------------------------------------------------------------------------
// helper function to print a KTrade
std::ostream& operator<<(std::ostream& os, const KTrade& kt);

//------------------------------------------------------------------------------

}; // namespace Kraken

//------------------------------------------------------------------------------

#endif


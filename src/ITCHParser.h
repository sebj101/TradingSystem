#pragma pack(push, 1)

#include <stdint.h>

struct ITCHMessageHeader {
  char messageType;
  uint16_t stockLocate;
  uint16_t trackingNumber;
  uint64_t timestamp;
};

struct SystemEventMessage {
  ITCHMessageHeader header;
  char eventCode;
};

struct AddOrderMessage {
  ITCHMessageHeader header;
  uint64_t orderRefNumber;
  char buySellIndicator;
  uint32_t shares;
  char stock[8];
  uint32_t price;
};

#pragma pack(pop)
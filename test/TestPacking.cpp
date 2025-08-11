// TestPacking.cpp

#include <cstdint>
#include <iostream>

// Default packing
struct UnpackedHeader {
  char messageType;
  uint16_t stockLocate;
  uint16_t trackingNumber;
  uint64_t timestamp;
};

// Packed to 1-byte alignment
#pragma pack(push, 1)
struct PackedHeader {
  char messageType;
  uint16_t stockLocate;
  uint16_t trackingNumber;
  uint64_t timestamp;
};
#pragma pack(pop)

int main() {
  std::cout << "Unpacked struct size: " << sizeof(UnpackedHeader) << " bytes\n";
  std::cout << "Packed struct size: " << sizeof(PackedHeader) << " bytes\n";

  // Show member offsets
  UnpackedHeader unpacked;
  PackedHeader packed;

  std::cout << "\nUnpacked offsets:\n";
  std::cout << "messageType: "
            << (char*)&unpacked.messageType - (char*)&unpacked << "\n";
  std::cout << "stockLocate: "
            << (char*)&unpacked.stockLocate - (char*)&unpacked << "\n";
  std::cout << "timestamp: " << (char*)&unpacked.timestamp - (char*)&unpacked
            << "\n";

  std::cout << "\nPacked offsets:\n";
  std::cout << "messageType: " << (char*)&packed.messageType - (char*)&packed
            << "\n";
  std::cout << "stockLocate: " << (char*)&packed.stockLocate - (char*)&packed
            << "\n";
  std::cout << "timestamp: " << (char*)&packed.timestamp - (char*)&packed
            << "\n";

  return 0;
}
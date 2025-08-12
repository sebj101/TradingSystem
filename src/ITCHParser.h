/// ITCHParser.h - Header file containing structs representing

#ifndef ITCH_PARSER_H
#define ITCH_PARSER_H

#include <cstdint>

#pragma pack(push, 1)

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
  /// @brief Message generated for unattributed orders accepted by Nasdaq system
  ITCHMessageHeader header;
  uint64_t orderRefNumber;
  char buySellIndicator;  // B = buy order, S = sell order
  uint32_t shares;        // Total number of shares associated with the order
  char stock[8];          // Stock symbol
  uint32_t price;         // Display price of the new order
};

struct AddOrderMPIDMessage {
  /// @brief Message generated for attributed orders accepted by Nasdaq system
  ITCHMessageHeader header;
  uint64_t orderRefNumber;
  char buySellIndicator;  // B = buy order, S = sell order
  uint32_t shares;        // Total number of shares associated with the order
  char stock[8];          // Stock symbol
  uint32_t price;         // Display price of the new order
  char attribution[4];    // Nasdaq market participant ID
};

struct OrderExecutedMessage {
  /// @brief Message sent whenever an order on the book is executed (in whole or
  /// part)
  ITCHMessageHeader header;
  uint64_t orderRefNumber;
  uint32_t executedShares;  // Number of shares executed
  uint64_t matchNumber;     // Nasdq generated day unique Match Number
};

struct OrderExecutedPriceMessage {
  /// @brief Message sent whenever an order on the book is executed (in whole or
  /// part) at a price different from the initial display proce
  ITCHMessageHeader header;
  uint64_t orderRefNumber;
  uint32_t executedShares;  // Number of shares executed
  uint64_t matchNumber;     // Nasdq generated day unique Match Number
  char printable;           // N = non-printable, Y = printable
  uint32_t executionPrice;  // Price at which order execution occurred
};

struct OrderCancelMessage {
  /// @brief Message sent whenever an order on the book is modified as a result
  /// of a partial cancellation
  ITCHMessageHeader header;
  uint64_t orderRefNumber;
  uint32_t cancelledShares;  // Number of shares being removed from the display
                             // size of the order
};

struct OrderDeleteMessage {
  /// @brief Message sent whenever an order on the book is being cancelled.
  ITCHMessageHeader header;
  uint64_t orderRefNumber;
};

struct OrderReplaceMessage {
  ITCHMessageHeader header;
  uint64_t orderRefNumber;
  uint64_t newOrderRefNumber;
  uint32_t shares;
  uint32_t price;
};

/// Trade messages

struct TradeMessage {
  ITCHMessageHeader header;
  uint64_t orderRefNumber;
  char buySellIndicator;
  uint32_t shares;
  char stock[8];
  uint32_t price;
  uint64_t matchNumber;
};

struct CrossTradeMessage {
  ITCHMessageHeader header;
  uint64_t shares;
  char stock[8];
  uint32_t crossPrice;
  uint64_t matchNumber;
  char crossType;  // O = Nasdaq opening cross, C = Nasdaq closing cross, H =
                   // cross for IPO and halted / paused securities
};

struct BrokenTradeMessage {
  ITCHMessageHeader header;
  uint64_t matchNumber;
};

struct NOIIMessage {
  /// @brief Net Order Imbalance Indicator
  ITCHMessageHeader header;
  uint64_t pairedShares;
  uint64_t imbalanceShares;
  char imbalanceDirection;  // B = buy imbalance, S = sell imbalance
  char stock[8];
  uint32_t farPrice;
  uint32_t nearPrice;
  uint32_t currentRefPrice;
  char crossType;
  char priceVariationIndicator;
};

#pragma pack(pop)

#endif
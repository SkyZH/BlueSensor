#ifndef ENVSENSOR_DATA_H
#define ENVSENSOR_DATA_H

#define DHTTYPE DHT22
#define DHTPIN 8

#define DATA_CMD_TEMPERATURE 97
#define DATA_CMD_BME_TEMPERATURE_C 100
#define DATA_CMD_BME_HUMIDITY 101
#define DATA_CMD_BME_PRESSURE 105

#define DATA_CMD_PM 65
#define DATA_CMD_PM01 70
#define DATA_CMD_PM25 71
#define DATA_CMD_PM10 72

#define DATA_CMD_DEBUG 66
#define DATA_CMD_FAILED 98
#define DATA_CMD_CLEAR 67
#define DATA_CMD_FAILED_BME 110
#define DATA_CMD_FAILED_PM 111

#define PACK_PAYLOAD_LENGTH 8
#define DATA_LENGTH 16

typedef unsigned char CMD;
typedef unsigned char SIZE;

union Payload {
  byte payload[PACK_PAYLOAD_LENGTH];
  int _int;
  long _long;
  float _float;
  double _double;
} Payload;

struct Packet {
  unsigned short message_id, response_id, command_id;
  union Payload payload;
  unsigned char _verification;
  unsigned char verification;
} Packet;

union Data {
  struct Packet packet;
  char data[DATA_LENGTH];
} Data;

struct BMEData {
  float h, t, p;
} BMEData;

struct PMData {
  int pm01, pm25, pm10;
} PMData;

#endif

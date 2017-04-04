
struct Beacon {
  char factoryId[9];
  char uuid[33];
  long major;
  long minor;
  long txPower;
  char mac[13];
  int rssi;
  float distance;
};
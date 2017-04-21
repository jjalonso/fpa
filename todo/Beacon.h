
struct Beacon {
  char factory_id[9];
  char uuid[33];
  long major;
  long minor;
  long tx_power;
  char mac[13];
  int rssi;
  float distance;
};
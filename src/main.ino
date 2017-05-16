
// #include "Beacon.h"
// #include "Buzzer.h"
// #include <Arduino.h>


// #include "Bluetooth.h"
// #include "Transition.h"





// Buzzer buzzer = Buzzer(10);

Bluetooth bluetooth = Bluetooth();
// Transition toFake = Transition("xxx", bluetooth, fakeState);

// Transition scanTransitions[1] = {
//   toFake
// }



// struct Record {
//   int personId;
//   char uuid[33];  
// };


// const bool DEBUG = true;
// const int MAX_RECORDS_PER_PERSON = 5;
// const int MAX_PERSON = 3;
// const int MAX_SCANNED_DEVICES = 6;

// const Record recordList[2] = {
//   { 1, "FE19575F9F514B7CAEDADE66F1D1AE4C" },
//   { 1, "8457E6845EC3408B9DEB72C92B910229" } 
// };

// // Patterns to parse
// const char BT_START_INPUT[9] = "OK+DISIS";
// const char BT_DEVICE_INPUT[9] = "OK+DISC:";
// const char BT_END_INPUT[9] = "OK+DISCE";

// struct Beacon scanResult[MAX_SCANNED_DEVICES];
// int scanResultIndex;

// // enum BTState currentBTState;
// char BTBuffer[78];
// int BTBufferIndex;
// char *strFound;
// boolean isBTScanning;







//
//
//
// void clearBTBuffer() {
//   BTBufferIndex = 0;
//   memset(BTBuffer, '\0', 78);
// }



//
// Change the current state Context state
//
// void setBTState(BTState nextState) {
//   clearBTBuffer();
//   currentBTState = nextState;
//   if (DEBUG) {
//     Serial.print("State changed to: ");
//     Serial.println(currentBTState);  
//   }
// }



//
// Read from BT serial
//
// void pumpBTBuffer() {
//   char c = BTSerial.read();
//   if (BTBufferIndex < 300 -1) {
//     BTBuffer[BTBufferIndex++] = c;
//     BTBuffer[BTBufferIndex] = 0 ;
//   }      
// }



//
// Setup module BT
//
// void setupBT() {
//   btCommand("AT+NAMEClueless");
//   btCommand("AT+ROLE1");
//   btCommand("AT+IMME1");
//   btCommand("AT+RESET");
// }



//
// Send a command through BTSerial
//
// void btCommand(const char* at) {
//   BTSerial.write(at);
//   delay(100);
// }



//
// Calculate beacon distance (Source: http://developer.radiusnetworks.com/2014/12/04/fundamentals-of-beacon-ranging.html)
//
// float calculateDistance(float txPower, float rssi) {  
  
//   float d = pow(10, ((double) txPower - rssi) / (10 * 2));
//   return d;
// }


//
// Build a beacon struct parsing a string
//
// Beacon buildBeacon(char* str) {
//   Beacon newBeacon;
//   // factoryId
//   strncpy(newBeacon.factoryId, str + 8, 16 - 8);
//   newBeacon.factoryId[8] = '\0';
//   // uuid
//   strncpy(newBeacon.uuid, str + 17, 49 - 17);
//   newBeacon.uuid[32] = '\0';
//   // major
//   char majorHex[5];
//   strncpy(majorHex, str + 50, 54 - 50);
//   majorHex[4] = '\0';
//   newBeacon.major = strtol(majorHex, NULL, 16);
//   // minor
//   char minorHex[5];
//   strncpy(minorHex, str + 54, 58 - 54);
//   minorHex[4] = '\0';
//   newBeacon.minor = strtol(minorHex, NULL, 16);
//   // txPower
//   char txPowerHex[3];
//   strncpy(txPowerHex, str + 58, 60 - 58);
//   txPowerHex[2] = '\0';
//   long unsignedTxPower = strtol(txPowerHex, NULL, 16);
//   newBeacon.txPower = -unsignedTxPower;
//   // mac
//   strncpy(newBeacon.mac, str + 61, 73 - 61);
//   newBeacon.mac[12] = '\0';
//   // rssi
//   newBeacon.rssi = atoi(str + 74);
//   // distance
//   float dist = calculateDistance(newBeacon.txPower, newBeacon.rssi);  
//   newBeacon.distance = dist;
//   if (dist < 3) {
//     buzzer.beep();
//   }
  
//   return(newBeacon);
// }


//
//
//
// void getRecordsByPersonId(Record * pPersonRecords, int recordsSize, int personId) {
//   int recordIndex = 0;
//   for (int x = 0; x < recordsSize; x++) {
// //      Serial.println((int) recordList[x].personId);

//     if ((int) recordList[x].personId == personId) {
//       pPersonRecords[recordIndex] = recordList[x];      
//       recordIndex++;
//     }
//   }
// }



//
//
//
// int findPerson(int* persons, int personId) {

//   for(int i = 0; i < MAX_PERSON; i++) {
//     if(persons[i] == personId) {
      
//       return i; 
//     }
//   }

//   return -1;
// }



//
//
//
// void addPerson(int* persons, int personId) {
//   for (int i = 0; i < MAX_PERSON; i++) {
//      if(persons[i] == 0) {
//        persons[i] = personId;

//        break;
//      }
//   }
// }



//
//
//
// void getPersonsInScan(int* persons) {
//   int currentPerson;
//   int personIndex;
  
//   for (int i = 0; i < MAX_SCANNED_DEVICES; i++) {
//     if (scanResult[i].minor != 0) {
//       currentPerson = scanResult[i].minor;
//       personIndex = findPerson(persons, currentPerson);
         
//       // If it is a new person
//       if (personIndex == -1) { 
//         // Add person
//         addPerson(persons, currentPerson);
//       }
//     }
    
//     return false;
//   } 
// }



//
//
//
// bool isRecordInResult(char* uuid) {
//   for (int i = 0; i < MAX_SCANNED_DEVICES; i++) {
  
//     if (scanResult[i].minor != 0) { // not empty
//       if (strcmp(uuid, scanResult[i].uuid) == 0) {
        
//         return true;
//       }      
//     }
//   }
  
//   return false;
// }



//
//
//
// bool checkBeacons() {
//   int persons[MAX_PERSON] = {0};
//   getPersonsInScan(persons);
  
//   for (int i = 0; i < MAX_PERSON; i++) {
//     if (persons[i] != 0) { // Not empty
//       struct Record personRecords[MAX_RECORDS_PER_PERSON] = {};
//       int recordsSize = sizeof(recordList) / sizeof(Record);
//       getRecordsByPersonId(personRecords, recordsSize, persons[i]);
      
//       for (int x = 0; x < MAX_RECORDS_PER_PERSON; x++) {
//         if (personRecords[x].personId != 0) { // not empty        
//           bool isRecordIn = isRecordInResult(personRecords[x].uuid);
//           if (isRecordIn == false) {
            
//             return false;
//           }
//         }
//       }
//     }            
//   }
  
//   return true;
// }



//
//
//
// void addToResult(Beacon beacon) {
//   scanResult[scanResultIndex] = beacon;
//   scanResultIndex++;
//   // DEBUG
//   if (DEBUG) {
//     Serial.print("Beacon { ");
//     Serial.print(beacon.factoryId);
//     Serial.print(" | ");
//     Serial.print(beacon.uuid);
//     Serial.print(" | ");
//     Serial.print(beacon.major);
//     Serial.print(" | ");
//     Serial.print(beacon.minor);    
//     Serial.print(" | ");
//     Serial.print(beacon.txPower);
//     Serial.print(" | ");
//     Serial.print(beacon.mac);
//     Serial.print(" | ");
//     Serial.print(beacon.rssi);
//     Serial.print(" | ");
//     Serial.print(beacon.distance);    
//     Serial.println(" }");
//   }
// }




//
// 
//
// void resetResult() {
// //  struct Beacon scanResult[6] = {};
//   memset(scanResult, 0, MAX_SCANNED_DEVICES);
//   scanResultIndex = 0;
// }


//
// Main Arduino setup()
//
void setup() {
  Serial.begin(9600);

  // buzzer.begin();
  bluetooth.begin(12, 11);


  // Serial.begin(115200);
  // BTSerial.begin(9600);
  // setupBT();
  // delay(1000);
  // isBTScanning = false;
  // setBTState(INQ_START);
}




//
// Main Arduino loop()
//
void loop() {
  bluetooth.update();
  delay(2000);
  
  // bluetooth.update();





















  // Bluetooth state Context
  
//   switch(currentBTState) {
    
//     case INQ_START:
//       if (!isBTScanning) {
//         resetResult();
//         isBTScanning = true;        
//         btCommand("AT+DISI?");
//       }
        
//       while (BTSerial.available()) {
//         pumpBTBuffer();
        
//         strFound = strstr(BTBuffer, BT_START_INPUT);
//         if (strFound) { setBTState(INQ_DEVICE); break; }
//         strFound = strstr(BTBuffer, BT_END_INPUT);
//         if (strFound) { setBTState(INQ_END); break; }
//       }
        
//       break;      
      
//     case INQ_DEVICE:
//       while (BTSerial.available() > 0) {
//         pumpBTBuffer();
   
//         strFound = strstr(BTBuffer, BT_DEVICE_INPUT);
//         if (strFound) { 
//             // Wait to receive full beacon
//             if (strlen(BTBuffer) == 78) {
//               // Add it to result
//               Beacon b = buildBeacon(BTBuffer);
//               if (b.major == 30987) {
//                 addToResult(b);   
//               }
//               clearBTBuffer();
              
//               break;  
//             } 
//         }        
//         strFound = strstr(BTBuffer, BT_END_INPUT);
//         if (strFound) { setBTState(INQ_END); break;}
//       }  
//       break;   
           
//     case INQ_END:
//       isBTScanning = false;
// //      bool isAllFound = checkBeacons();
// //      if (isAllFound == false) {
// //        beep();
// //      }
      
//       setBTState(INQ_START);
//       break;  
//   }
}
















//void sortResult() {  
//  Beacon temp;
//  int sizeResult = sizeof(scanResult) / sizeof(struct Beacon);
//  for (int x = 0; x < sizeResult; x++) {
//     for (int y = 0; y < sizeResult - 1; y++) {
//       if (scanResult[y].rssi < scanResult[y+1].rssi) {
//         temp = scanResult[y+1];
//         scanResult[y+1] = scanResult[y];
//         scanResult[y] = temp;
//       }
//     }
//  }
//  if (DEBUG) {
//    Serial.println("Sorted (RSSI):");
//    for (int i = 0; i < 6; i++) {
//      Serial.print("> ");
//      Serial.println(scanResult[i].rssi);
//    }      
//  }
//
//}




/*
 https://www.electronicwings.com/
  SD Card Interface code for ESP32
  SPI Pins of ESP32 SD card as follows:
  SS    = 5;
  MOSI  = 23;
  MISO  = 19;
  SCK   = 18; 
*/
#include "FS.h"
#include <SPI.h>
#include <SD.h>

//#define HSPI_SCK 14
//#define HSPI_MISO 12
//#define HSPI_MOSI 13
//#define HSPI_CS 15

//#define VSPI_SCK 18
//#define VSPI_MISO 19
//#define VSPI_MOSI 23
//#define VSPI_CS 5 5,23

#define mySS 26
#define mySCK 27
#define myMISO 13
#define myMOSI 14


File myFile;
//const int CS = 5;

void setup() {
  Serial.begin(115200);    // Set serial baud rate to 9600
  delay(500);
  while (!Serial) { ; }  // wait for serial port to connect. Needed for native USB port only

  //SPI manual format:::: SPI.begin(SCK,MISO, MOSI, SS);
  SPI.begin(SCK,MISO,MOSI,SS);
  
  Serial.println("Initializing SD card...");
  if (!SD.begin(SS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  WriteFile(SD, "/03_03_2023_00_37_25.txt", "TimeStamp FSR1press FSR2press FSR3press  [mmHg]\r\n");
  ReadFile(SD, "/03_03_2023_00_37_25.txt");
}

void loop() {
  // nothing happens after setup
}

void WriteFile(fs::FS &fs, const char * path, const char * message){
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = fs.open(path, FILE_WRITE);
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.printf("Writing to %s ", path);
    myFile.println(message);
    myFile.close(); // close the file:
    Serial.println("completed.");
  } 
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening file ");
    Serial.println(path);
  }
}


void ReadFile(fs::FS &fs, const char * path){
  // open the file for reading:
  myFile = fs.open(path);
  if (myFile) {
     Serial.printf("Reading file from %s\n", path);
     // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close(); // close the file:
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}



//=====================================

//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(115200);
//  Serial.print("MOSI: ");
//  Serial.println(MOSI);
//  Serial.print("MISO: ");
//  Serial.println(MISO);
//  Serial.print("SCK: ");
//  Serial.println(SCK);
//  Serial.print("SS: ");
//  Serial.println(SS);  
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//}

//=================================================================================================
//#include <SPI.h>
////#include <SD.h>
//#include "C:\Users\user00\AppData\Local\Arduino15\packages\esp32\hardware\esp32\1.0.6\libraries\SD\src\SD.h"
//
//File myFile;
//
//void setup() {
// // Open serial communications and wait for port to open:
// Serial.begin(115200);
// while (!Serial) {
//   ; // wait for serial port to connect. Needed for native USB port only
// }
//
//
// Serial.print("Initializing SD card...");
// Serial.print(SS);
// if (!SD.begin(SS)) {
//   Serial.println("initialization failed!");
//   while (1);
// }
// Serial.println("initialization done.");
//
// // open the file. note that only one file can be open at a time,
// // so you have to close this one before opening another.
// myFile = SD.open("test.txt", FILE_WRITE);
//
// // if the file opened okay, write to it:
// if (myFile) {
//   Serial.print("Writing to test.txt...");
//   myFile.println("testing 1, 2, 3.");
//   // close the file:
//   myFile.close();
//   Serial.println("done.");
// } else {
//   // if the file didn't open, print an error:
//   Serial.println("error opening test.txt");
// }
//
// // re-open the file for reading:
// myFile = SD.open("test.txt");
// if (myFile) {
//   Serial.println("test.txt:");
//
//   // read from the file until there's nothing else in it:
//   while (myFile.available()) {
//     Serial.write(myFile.read());
//   }
//   // close the file:
//   myFile.close();
// } else {
//   // if the file didn't open, print an error:
//   Serial.println("error opening test.txt");
// }
//}
//
//void loop() {
//  
//}

//===================================================================================

// #include "FS.h"
// #include "SD.h"
// #include "SPI.h"

// void listDir(fs::FS &fs, const char * dirname, uint8_t levels){
//     Serial.printf("Listing directory: %s\n", dirname);

//     File root = fs.open(dirname);
//     if(!root){
//         Serial.println("Failed to open directory");
//         return;
//     }
//     if(!root.isDirectory()){
//         Serial.println("Not a directory");
//         return;
//     }

//     File file = root.openNextFile();
//     while(file){
//         if(file.isDirectory()){
//             Serial.print("  DIR : ");
//             Serial.println(file.name());
//             if(levels){
//                 listDir(fs, file.name(), levels -1);
//             }
//         } else {
//             Serial.print("  FILE: ");
//             Serial.print(file.name());
//             Serial.print("  SIZE: ");
//             Serial.println(file.size());
//         }
//         file = root.openNextFile();
//     }
// }

// void createDir(fs::FS &fs, const char * path){
//     Serial.printf("Creating Dir: %s\n", path);
//     if(fs.mkdir(path)){
//         Serial.println("Dir created");
//     } else {
//         Serial.println("mkdir failed");
//     }
// }

// void removeDir(fs::FS &fs, const char * path){
//     Serial.printf("Removing Dir: %s\n", path);
//     if(fs.rmdir(path)){
//         Serial.println("Dir removed");
//     } else {
//         Serial.println("rmdir failed");
//     }
// }

// void readFile(fs::FS &fs, const char * path){
//     Serial.printf("Reading file: %s\n", path);

//     File file = fs.open(path);
//     if(!file){
//         Serial.println("Failed to open file for reading");
//         return;
//     }

//     Serial.print("Read from file: ");
//     while(file.available()){
//         Serial.write(file.read());
//     }
//     file.close();
// }

// void writeFile(fs::FS &fs, const char * path, const char * message){
//     Serial.printf("Writing file: %s\n", path);

//     File file = fs.open(path, FILE_WRITE);
//     if(!file){
//         Serial.println("Failed to open file for writing");
//         return;
//     }
//     if(file.print(message)){
//         Serial.println("File written");
//     } else {
//         Serial.println("Write failed");
//     }
//     file.close();
// }

// void appendFile(fs::FS &fs, const char * path, const char * message){
//     Serial.printf("Appending to file: %s\n", path);

//     File file = fs.open(path, FILE_APPEND);
//     if(!file){
//         Serial.println("Failed to open file for appending");
//         return;
//     }
//     if(file.print(message)){
//         Serial.println("Message appended");
//     } else {
//         Serial.println("Append failed");
//     }
//     file.close();
// }

// void renameFile(fs::FS &fs, const char * path1, const char * path2){
//     Serial.printf("Renaming file %s to %s\n", path1, path2);
//     if (fs.rename(path1, path2)) {
//         Serial.println("File renamed");
//     } else {
//         Serial.println("Rename failed");
//     }
// }

// void deleteFile(fs::FS &fs, const char * path){
//     Serial.printf("Deleting file: %s\n", path);
//     if(fs.remove(path)){
//         Serial.println("File deleted");
//     } else {
//         Serial.println("Delete failed");
//     }
// }

// void testFileIO(fs::FS &fs, const char * path){
//     File file = fs.open(path);
//     static uint8_t buf[512];
//     size_t len = 0;
//     uint32_t start = millis();
//     uint32_t end = start;
//     if(file){
//         len = file.size();
//         size_t flen = len;
//         start = millis();
//         while(len){
//             size_t toRead = len;
//             if(toRead > 512){
//                 toRead = 512;
//             }
//             file.read(buf, toRead);
//             len -= toRead;
//         }
//         end = millis() - start;
//         Serial.printf("%u bytes read for %u ms\n", flen, end);
//         file.close();
//     } else {
//         Serial.println("Failed to open file for reading");
//     }


//     file = fs.open(path, FILE_WRITE);
//     if(!file){
//         Serial.println("Failed to open file for writing");
//         return;
//     }

//     size_t i;
//     start = millis();
//     for(i=0; i<2048; i++){
//         file.write(buf, 512);
//     }
//     end = millis() - start;
//     Serial.printf("%u bytes written for %u ms\n", 2048 * 512, end);
//     file.close();
// }
 
// void setup(){
//     Serial.begin(115200);
//     pinMode(SS, OUTPUT);
//     if(!SD.begin(SS)){
//         Serial.println("Card Mount Failed");
//         return;
//     }
//     uint8_t cardType = SD.cardType();

//     if(cardType == CARD_NONE){
//         Serial.println("No SD card attached");
//         return;
//     }

//     Serial.print("SD Card Type: ");
//     if(cardType == CARD_MMC){
//         Serial.println("MMC");
//     } else if(cardType == CARD_SD){
//         Serial.println("SDSC");
//     } else if(cardType == CARD_SDHC){
//         Serial.println("SDHC");
//     } else {
//         Serial.println("UNKNOWN");
//     }

//     uint64_t cardSize = SD.cardSize() / (1024 * 1024);
//     Serial.printf("SD Card Size: %lluMB\n", cardSize);

//     listDir(SD, "/", 0);
//     createDir(SD, "/mydir");
//     listDir(SD, "/", 0);
//     removeDir(SD, "/mydir");
//     listDir(SD, "/", 2);
//     writeFile(SD, "/hello.txt", "Hello ");
//     appendFile(SD, "/hello.txt", "World!\n");
//     readFile(SD, "/hello.txt");
//     deleteFile(SD, "/foo.txt");
//     renameFile(SD, "/hello.txt", "/foo.txt");
//     readFile(SD, "/foo.txt");
//     testFileIO(SD, "/test.txt");
//     Serial.printf("Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
//     Serial.printf("Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));
// }

// void loop(){

// }

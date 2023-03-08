/* 
 * This library is (c) 2023 My Circuit.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "STS21lib.h"

STS21::STS21() {
  Wire.begin(21,22);
}


float STS21::readTemperatureC() 
{
  unsigned int data[2];

  // Start I2C Transmission
  Wire.beginTransmission(STS21_ADDRESS);
  // Select no hold master
  Wire.write(0xF3);
  // End I2C Transmission
  Wire.endTransmission();
  delay(300);

  // Request 2 bytes of data
  Wire.requestFrom(STS21_ADDRESS, 2);

  // Read 2 bytes of data
  if (Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }

  // Convert the data
  int rawtmp = data[0] * 256 + data[1];
  int value = rawtmp & 0xFFFC;
  double cTemp = -46.85 + (175.72 * (value / 65536.0));
  return cTemp;
}

float STS21::readTemperatureF() 
{
  unsigned int data[2];

  // Start I2C Transmission
  Wire.beginTransmission(STS21_ADDRESS);
  // Select no hold master
  Wire.write(0xF3);
  // End I2C Transmission
  Wire.endTransmission();
  delay(300);

  // Request 2 bytes of data
  Wire.requestFrom(STS21_ADDRESS, 2);

  // Read 2 bytes of data
  if (Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }

  // Convert the data
  int rawtmp = data[0] * 256 + data[1];
  int value = rawtmp & 0xFFFC;
  double cTemp = -46.85 + (175.72 * (value / 65536.0));
  double fTemp = cTemp * 1.8 + 32;
  return fTemp;
}

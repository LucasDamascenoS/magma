/*
  Copyright 2020 The Magma Authors.
  This source code is licensed under the BSD-style license found in the
  LICENSE file in the root directory of this source tree.
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include <iostream>
#include <sstream>
#include <cstdint>
#include "lte/gateway/c/core/oai/tasks/nas5g/include/ies/M5GSecurityHeaderType.hpp"
#include "lte/gateway/c/core/oai/tasks/nas5g/include/M5GCommonDefs.h"

namespace magma5g {
SecurityHeaderTypeMsg::SecurityHeaderTypeMsg() {};
SecurityHeaderTypeMsg::~SecurityHeaderTypeMsg() {};

// Decode SecurityHeaderType IE
int SecurityHeaderTypeMsg::DecodeSecurityHeaderTypeMsg(
    SecurityHeaderTypeMsg* sec_header_type, uint8_t iei, uint8_t* buffer,
    uint32_t len) {
  int decoded = 0;

  sec_header_type->sec_hdr = *(buffer) & 0xf;
  decoded++;
  return (decoded);
};

// Encode SecurityHeaderType IE
int SecurityHeaderTypeMsg::EncodeSecurityHeaderTypeMsg(
    SecurityHeaderTypeMsg* sec_header_type, uint8_t iei, uint8_t* buffer,
    uint32_t len) {
  int encoded = 0;

  *(buffer) = sec_header_type->sec_hdr & 0xf;
  encoded++;
  return (encoded);
};
}  // namespace magma5g

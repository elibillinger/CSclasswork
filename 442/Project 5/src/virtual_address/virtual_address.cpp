/**
 * This file contains implementations for methods in the VirtualAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "virtual_address/virtual_address.h"

using namespace std;

VirtualAddress VirtualAddress::from_string(int process_id, string address) {
    string page = address.substr(0,10);
    string offset = address.substr(10,16);
    return VirtualAddress(process_id, bitset<32>(page).to_ulong(), bitset<32>(offset).to_ulong());
}


string VirtualAddress::to_string() const {
    string address = bitset<10>(page).to_string() + bitset<6>(offset).to_string();
    return address;
}


ostream& operator <<(ostream& out, const VirtualAddress& address) {
    out << "PID " << address.process_id
      << " @ " << address.to_string()
      << " [page: " << address.page
      << "; offset: " << address.offset
      << "]";  
    return out;
}

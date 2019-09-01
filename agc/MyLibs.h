#ifndef ICL_BITS
#define ICL_BITS
#include <bits/stdc++.h>
#endif


std::string replaceAll(std::string &replacedStr, std::string from, std::string to) {
  int pos = replacedStr.find(from);
  int toLen = to.length();

  if (from.empty()) {
    return replacedStr;
  }

  while ((pos = replacedStr.find(from, pos)) != std::string::npos) {
    //cout << pos << endl;
    replacedStr.replace(pos, from.length(), to);
    pos += toLen;
  }
  return replacedStr;
}

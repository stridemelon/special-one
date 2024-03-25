 if (!i)                          
      {
        char* j = current - needle_len_less1;
        while (i < needle_len_less1 &&
          needle_ic_[i] == case_table[static_cast<unsigned>(*(j + i))]) ++i;
        if (i == needle_len_less1)
        {
          ++current;
          last_found = j;
          return true;
        }
        else
          current += jump_;
      }
      else
        current += i;
    }
    return false;
  }

public:

  explicit BMH_Search(std::ifstream& stream, 
    const std::string& needle = "")
  {
    //case blind table
    for (int c = 0; c < 0x61; ++c) case_table[c] = c;
    for (int c = 0x61; c < 0x7B; ++c) case_table[c] = c - 0x20;
    for (int c = 0x7B; c < 256; ++c) case_table[c] = c;

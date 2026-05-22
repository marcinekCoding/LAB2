void print_readable_character(std::byte byte)
// {
//     if (byte >= std::byte{0x20} && byte <= std::byte{0x7E})
//         std::cout << static_cast<char>(byte);
//     else
//         std::cout << ".";  // Non readable character cannot be shown in the console
// }

// void dump_memory(std::byte* start, size_t count)
// {
//     const long int window_width = 8;

//     // STAGE 3: Implement me!
//     // Hint: you can use print_readable_character function to print arbitrary byte as character
// }
/**
  cp437.c
  Convert text encoded with IBM Code Page 437 into equivalent Unicode glyphs
**/

#include <stdio.h>

const char CP437[256][4] = {
  "␀", "☺", "☻", "♥", "♦", "♣", "♠", "•", "◘", "○", "◙", "♂", "♀", "♪", "♫",
  "☼", "►", "◄", "↕", "‼", "¶", "§", "▬", "↨", "↑", "↓", "→", "←", "∟", "↔",
  "▲", "▼", " ", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",",
  "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";",
  "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
  "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y",
  "Z", "[", "\\", "]", "^", "_", "`", "a", "b", "c", "d", "e", "f", "g", "h",
  "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w",
  "x", "y", "z", "{", "|", "}", "~", "⌂", "Ç", "ü", "é", "â", "ä", "à", "å",
  "ç", "ê", "ë", "è", "ï", "î", "ì", "Ä", "Å", "É", "æ", "Æ", "ô", "ö", "ò",
  "û", "ù", "ÿ", "Ö", "Ü", "¢", "£", "¥", "₧", "ƒ", "á", "í", "ó", "ú", "ñ",
  "Ñ", "ª", "º", "¿", "⌐", "¬", "½", "¼", "¡", "«", "»", "░", "▒", "▓", "│",
  "┤", "╡", "╢", "╖", "╕", "╣", "║", "╗", "╝", "╜", "╛", "┐", "└", "┴", "┬",
  "├", "─", "┼", "╞", "╟", "╚", "╔", "╩", "╦", "╠", "═", "╬", "╧", "╨", "╤",
  "╥", "╙", "╘", "╒", "╓", "╫", "╪", "┘", "┌", "█", "▄", "▌", "▐", "▀", "α",
  "ß", "Γ", "π", "Σ", "σ", "µ", "τ", "Φ", "Θ", "Ω", "δ", "∞", "φ", "ε", "∩",
  "≡", "±", "≥", "≤", "⌠", "⌡", "÷", "≈", "°", "∙", "·", "√", "ⁿ", "²", "■",
  "⍽"
};

void print_cp437(unsigned char ch, int convert_cmds) {
  if(!convert_cmds && (ch == 0x00 || ch == 0x0A || ch == 0x0D || ch == 0x09 || ch == 0x1B)) {
    printf("%c", ch);
  } else {
    printf("%s", CP437[ch]);
  }
}

int main(int argc, char *argv[]) {
  int convert_cmds = 0; /* convert nl, tab, etc to glyphs */

  if(argc > 1) {
    if(argv[1][0] == 'C' || argv[1][0] == 'c') {
      convert_cmds = 1;
    }
  }

  int ch;

  while((ch = getchar()) != EOF) {
    unsigned char byte = (unsigned char)ch;

    print_cp437(byte, convert_cmds);
  }

  printf("\n");

  return 0;
}

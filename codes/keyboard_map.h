/* The following array is taken from
    http://www.osdever.net/bkerndev/Docs/keyboard.htm
   All credits where due
*/

unsigned char keyboard_map[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    128,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    201,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    200,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};
char ASC_CAP[257] = {' '
,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,8 ,' ',' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' '
,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,'!' ,'"' ,'#' ,'$' ,'%' ,'&'
,39 ,'(' ,')' ,'*' ,'+' ,'<'/*','*/ ,'_'/*'-'*/ ,'>' /*'.'*/,'?'/*'/'*/ ,


// AQUI E A POSICAO REFERENTE AOS NUMERAIS QUE FORAM SUBSTITUIDAS POR SIMBOLOS ESPECIAIS
//0   1   2     3    4    5   6     7   8    9    :      ;    <   =
')' ,'!' ,'@' ,'#' ,'$' ,'%' ,'¨' ,'&' ,'*' ,'(' ,';' ,':' ,',' ,'+'


,'>' ,'?' ,'@' ,'A' ,'B' ,'C' ,'D' ,'E' ,'F' ,'G'
,'H' ,'I' ,'J' ,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X'
,'Y' ,'Z' ,

// AQUI E A POSICAO REFERENTE AS CHARS MINUSCULAS QUE FORAM SUBSTITUIDAS POR MAIUSCULAS
//[   \    ]    ^    _    `     a  b    c    d    e    f   g     h    i
'{' ,'|' ,'}' ,'~' ,'-' ,'´' ,'A','B' ,'C' ,'D' ,'E' ,'F' ,'G' ,'H' ,'I'
,'J' ,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y' ,'Z'


,'{' ,'|' ,'}' ,'~' ,'⌂' ,'Ç' ,'ü' ,'é' ,'â' ,'ä' ,'à' ,'å' ,'ç' ,'ê' ,'ë' ,'è' ,'ï'
,'î' ,'ì' ,'Ä' ,'Å' ,'É' ,'æ' ,'Æ' ,'ô' ,'ö' ,'ò' ,'û' ,'ù' ,'ÿ' ,'Ö' ,'Ü' ,'ø' ,'£'
,'Ø' ,'×' ,'ƒ' ,'á' ,'í' ,'ó' ,'ú' ,'ñ' ,'Ñ' ,'ª' ,'º' ,'¿' ,'®' ,'¬' ,'½' ,'¼' ,'¡'
,'«' ,'»' ,'░' ,'▒' ,'▓' ,'│' ,'┤' ,'Á' ,'Â' ,'À' ,'©' ,'╣' ,'║' ,'╗' ,'╝' ,'¢' ,'¥'
,'┐' ,'└' ,'┴' ,'┬' ,'├' ,'─' ,'┼' ,'ã' ,'Ã' ,'╚' ,'╔' ,'╩' ,'╦' ,'╠' ,'═' ,'╬' ,'¤'
,'ð' ,'Ð' ,'Ê' ,'Ë' ,'È' ,'ı' ,'Í' ,'Î' ,'Ï' ,'┘' ,'┌' ,'█' ,'▄' ,'¦' ,'Ì' ,'▀' ,'Ó'
,'ß' ,'Ô' ,'Ò' ,'õ' ,'Õ' ,'µ' ,'þ' ,'Þ' ,'Ú' ,'Û' ,'Ù' ,'ý' ,'Ý' ,'¯' ,'´' ,'­' ,'±'
,'‗' ,'¾' ,'¶' ,'§' ,'÷' ,'¸' ,'°' ,'¨' ,'·' ,'¹' ,'³' ,'²' ,' ' ,' '};

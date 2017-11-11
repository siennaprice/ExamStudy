void send_string(char *str)
{
size_t len; // a size_t is an unsigned integer
len = strlen(str); // returns the number of chars in str
for (i = 0; i < len; i++) {
// send this character
	do {
		err = UART_SendChar(str[i]);
	} while (err != ERR_OK);
}
}

// Flash the LED
int counter;
for (;;) {
	GPIOC_PDOR = 0;
	for (counter = 0; counter < 5000000; counter++) {
		// spin
	}
	GPIOC_PDOR = (1 << 3);
	for (counter = 0; counter < 1000000; counter++) {
		// spin
	}
}
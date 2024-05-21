#include "minichess.hpp"
    
int main() {
    // Uart uart;
    // Adc adc;
    // Twi twi;

    // ButtonManager button_manager(adc);
    // Display display(twi, uart);
    // ChessBoard chessBoard(display);

    // while (1) {
    //     Button button = button_manager.getButtonPress();



    //     _delay_ms(500);

    //     display.display();
    // }
    Minichess minichess;
    minichess.run();
    
    return 0;
}

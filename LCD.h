void ProgramCustomChars()
{

    Lcd8_Cmd (64);

    // Forward Arrow

    Lcd8_Chr_Cp(0b00000100);
    Lcd8_Chr_Cp(0b00001110);
    Lcd8_Chr_Cp(0b00010101);
    Lcd8_Chr_Cp(0b00000100);
    Lcd8_Chr_Cp(0b00000100);
    Lcd8_Chr_Cp(0b00000100);
    Lcd8_Chr_Cp(0b00000100);
    Lcd8_Chr_Cp(0b00000000);

    // Backward Arrow

    Lcd8_Chr_Cp(0b00000000);
    Lcd8_Chr_Cp(0b00000100);
    Lcd8_Chr_Cp(0b00000100);
    Lcd8_Chr_Cp(0b00000100);
    Lcd8_Chr_Cp(0b00000100);
    Lcd8_Chr_Cp(0b00010101);
    Lcd8_Chr_Cp(0b00001110);
    Lcd8_Chr_Cp(0b00000100);

    // Empty Square

    Lcd8_Chr_Cp(0b00011111);
    Lcd8_Chr_Cp(0b00010001);
    Lcd8_Chr_Cp(0b00010001);
    Lcd8_Chr_Cp(0b00010001);
    Lcd8_Chr_Cp(0b00010001);
    Lcd8_Chr_Cp(0b00010001);
    Lcd8_Chr_Cp(0b00010001);
    Lcd8_Chr_Cp(0b00011111);

    // Filled Square

    Lcd8_Chr_Cp(0b00011111);
    Lcd8_Chr_Cp(0b00011111);
    Lcd8_Chr_Cp(0b00011111);
    Lcd8_Chr_Cp(0b00011111);
    Lcd8_Chr_Cp(0b00011111);
    Lcd8_Chr_Cp(0b00011111);
    Lcd8_Chr_Cp(0b00011111);
    Lcd8_Chr_Cp(0b00011111);

    Lcd8_Cmd(Lcd_Return_Home);
}

void Intialize_LCD()
{
    Lcd8_Init(&PORTD, &PORTB);

    Lcd8_Cmd(LCD_CURSOR_OFF);
    
    ProgramCustomChars();
    
    strcp_c(lcd1, lcd1_default);
    
    strcp_c(lcd2, lcd2_default);
    
    
}

void DisplayScreen1()
{
    Lcd8_Cmd(LCD_CLEAR);
    
    strcpy(temp, lcd1);
    
    Lcd8_Out(1, 1, temp);

    strcpy(temp, lcd2);
    
    Lcd8_Out(2, 1, temp);
    
    lcd_screen = 1;
}

void DisplayScreen2()
{
    Lcd8_Cmd(LCD_CLEAR);
    
    Lcd8_Chr(1,3,'1');
    
    Lcd8_Chr(1,8,'2');
    
    Lcd8_Chr(1,13,'3');
    
    LCD8_Chr(2, 2, (AXIS1_ENABLE_BIT) ? 3 : 2);

    LCD8_Chr(2, 4, (AXIS1_DIRECTION_BIT) ? 1 : 0);

    LCD8_Chr(2, 7, (AXIS2_ENABLE_BIT) ? 3 : 2);

    LCD8_Chr(2, 9, (AXIS2_DIRECTION_BIT) ? 1 : 0);

    LCD8_Chr(2, 12, (AXIS3_ENABLE_BIT) ? 3 : 2);
    
    LCD8_Chr(2, 14, (AXIS3_DIRECTION_BIT) ? 1 : 0);

    lcd_screen = 2;
}










#include <kipr/botball.h>

void forwards(int m);
void reverse(int m);
void right(int m);
void left(int m);
void claw_up(int m);
void claw_down(int m);
void claw_open(int m);
void claw_closed(int m);
int a=0;
int s=1350;
int main()
{
    enable_servos();
    set_servo_position(0,0);
    set_servo_position(1,1350);

    while((digital(0)==0)&&(digital(1)==0))		//back up til bumpers touched
    {
        motor(0,-50);
        motor(3,-50);
    }
    printf ("bumpers touched!\n");
    msleep(300);

    forwards(1200);
    //go to utility poles
    right(900);
    forwards(6000);
    //set up to connect poles
    left(1900);
    while((digital(0)==0)&&(digital(1)==0))
    {
        motor(0,-50);
        motor(3,-50);
    }
    //connect utility poles
    motor(0,-30);
    motor(3,30);
    msleep(500);
    ao();
    claw_open(1100);
    claw_down(100);
    motor(0,-30);
    motor(3,30);
    msleep(850);
    ao();
    forwards(200);
    claw_down(300);
    reverse(400);
    claw_down(530);
    reverse(1000);
    claw_open(1100);
    //reverse(200);
    claw_up(700);
    right(100);
    reverse(500);
    msleep(300);
    //go to other utility pole
    claw_down(1200);
    claw_closed(1350);
    disable_servos();
    return 0;
}

void forwards(int m)
{
    cmpc(0);
    while(gmpc(0)<m)
    {
        motor(0,70);
        motor(3,70);
    }
    motor(0,-50);
    motor(3,-50);
    msleep(50);
    ao();
}
void reverse(int m)
{
    cmpc(0);
    while(gmpc(0)>-m)
    {
        motor(0,-70);
        motor(3,-70);
    }
    motor(0,50);
    motor(3,50);
    msleep(50);
    ao();
}
void right(int m)
{
    motor(0,-50);
    motor(3,50);
    msleep(m);
    ao();
}
void left(int m)
{
    motor(0,50);
    motor(3,-50);
    msleep(m);
    ao();
}
void claw_up(int m)
{
    while(m<=a)
    {
        set_servo_position(0,a);
        msleep(50);
        a=a-10;
    }
}
void claw_down(int m)
{
    while(m>=a)
    {
        set_servo_position(0,a);
        msleep(50);
        a=a+10;
    }
}
void claw_open(int m)
{
    while(m<=s)
    {
        set_servo_position(1,s);
        msleep(50);
        s=s-10;
    }
}
void claw_closed(int m)
{
    while(m>=s)
    {
        set_servo_position(1,s);
        msleep(50);
        s=s+10;
    }
}
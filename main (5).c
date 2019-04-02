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

    while((digital(0)==0)||(digital(1)==0))		//back up til bumpers touched
    {
        motor(0,-50);
        motor(3,-50);
    }
  
    forwards(1200);
    //go to utility poles
    right(900);
    forwards(6000);
    //set up to connect poles
    left(1800);
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
    claw_open(1000);
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
    claw_closed(1100);
    claw_up(700);
    left(150);
    reverse(800);
    msleep(300);
    //go to other utility pole
    while(1200>=a)
    {
        set_servo_position(0,a);
        msleep(1);
        a=a+1;
    }
    a=1200;
    while(1350>=s)
    {
        set_servo_position(1,s);
        msleep(1);
        s=s+1;
    }
    s=1350;
    forwards(1800);
    right(450);
    //connect other utility pole
    forwards(200);
    claw_open(1100);
    left(100);
    forwards(700);
    claw_up(1000);
    right(100);
    forwards(1200);
    claw_up(700);
    //left(150);
    forwards(1000);
    claw_up(600);
    forwards(750);
    left(200);
    forwards(100);
    claw_down(750);
    claw_closed(1200);
    reverse(1500);
    claw_down(1100);
    left(400);
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

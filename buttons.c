#define USEBTN(x)  int btnState##x = 0; int lastBtnState##x = 0
#define UPDATEBTN(x)  lastBtnState##x = btnState##x; btnState##x = vexRT[x]
#define GETBTN(x)  btnState##x
#define GETLASTBTN(x)  lastBtnState##x
#define BTNPRESSED(x)  (btnState##x && !lastBtnState##x)
#define BTNRELEASED(x)	(!btnState##x && lastBtnState##x)

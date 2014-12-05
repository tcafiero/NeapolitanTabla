#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>



static enum midi::MidiType type;
static midi::DataByte note, data2;
static midi::Channel channel;


MIDI_CREATE_INSTANCE(HardwareSerial, Serial,     midiA);

void setup()
{
  midiA.begin(0);
  midiA.turnThruOff();
}

void loop()
{
#if 0
  midiA.send(midi::NoteOn, 0x30, 0x6E, 3);
  delay(1000);
#endif
#if 1

  if (midiA.read())
  {
    type = midiA.getType();
    note = midiA.getData1();
    data2 = midiA.getData2();
    channel = midiA.getChannel();
    switch (channel)
    {
      case 0x2:  switch (note)
        {
          case 0x37:
            note = 0x2B;
            channel = 0x2;
            break;
          case 0x48:
            note = 0x3C;
            channel = 0x2;
            break;
          case 0x52:
            note = 0x46;
            channel = 0x2;
            break;
          case 0x60:
            note = 0x54;
            channel = 0x5;
            break;
          default: break;
        };
        break;
      case 0x3:  switch (note)
        {
          case 0x18:
            note = 0x0C;
            channel = 0x2;
            break;
          case 0x37:
            note = 0x2A;
            channel = 0x3;
            break;
          case 0x3C:
            note = 0x30;
            channel = 0x3;
            break;
          case 0x48:
            note = 0x3C;
            channel = 0x3;
            break;
          default: break;
        };
        break;
      case 0x4:  switch (note)
        {
          case 0x11:
            note = 0x04;
            channel = 0x4;
            break;
          case 0x13:
            note = 0x07;
            channel = 0x4;
            break;
          case 0x24:
            note = 0x18;
            channel = 0x4;
            break;
          case 0x30:
            note = 0x24;
            channel = 0x5;
            break;
          default: break;
        };
        break;
      case 0x5:  switch (note)
        {
          case 0x30:
            note = 0x24;
            channel = 0x3;
            break;
          case 0x3E:
            note = 0x32;
            channel = 0x5;
            break;
          case 0x4E:
            note = 0x42;
            channel = 0x5;
            break;
          default: break;
        };
        break;
      case 0xC:
        switch (note)
        {
          case 0x0C:
            note = 0x00;
            channel = 0x4;
            break;
          default: break;
        };
        break;
      default: break;
    };
    // Thru on A has already pushed the input message to out A.
    // Forward the message to out B as well.
    midiA.send(type, note, data2, channel);
  }
#endif

}

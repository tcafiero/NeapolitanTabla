#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>



static enum midi::MidiType type;
static midi::DataByte data1, data2;
static midi::Channel channel;


MIDI_CREATE_INSTANCE(HardwareSerial, Serial,     midiA);

void setup()
{
  midiA.begin(MIDI_CHANNEL_OMNI);
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
    data1 = midiA.getData1();
    data2 = midiA.getData2();
    channel = midiA.getChannel();
    switch (type)
    {
      case midi::NoteOff:
      case midi::NoteOn:
        {
          switch (channel)
          {
            case 2:  switch (data1)
              {
                case 0x37:
                  data1 = 0x2B;
                  channel = 2;
                  break;
                case 0x48:
                  data1 = 0x3C;
                  channel = 2;
                  break;
                case 0x52:
                  data1 = 0x18;
                  channel = 10;
                  break;
                case 0x60:
                  data1 = 0x54;
                  channel = 5;
                  break;
                default: break;
              };
              break;
            case 3:  switch (data1)
              {
                case 0x18:
                  data1 = 0x18;
                  channel = 2;
                  break;
                case 0x37:
                  data1 = 0x2B;
                  channel = 3;
                  break;
                case 0x3C:
                  data1 = 0x30;
                  channel = 3;
                  break;
                case 0x48:
                  data1 = 0x3C;
                  channel = 3;
                  break;
                default: break;
              };
              break;
            case 4:  switch (data1)
              {
                case 0x11:
                  data1 = 0x28;
                  channel = 4;
                  break;
                case 0x13:
                  data1 = 0x2B;
                  channel = 4;
                  break;
                case 0x24:
                  data1 = 0x30;
                  channel = 4;
                  break;
                case 0x30:
                  data1 = 0x24;
                  channel = 5;
                  break;
                default: break;
              };
              break;
            case 5:  switch (data1)
              {
                case 0x30:
                  data1 = 0x24;
                  channel = 3;
                  break;
                case 0x3E:
                  data1 = 0x32;
                  channel = 5;
                  break;
                case 0x4E:
                  data1 = 0x42;
                  channel = 5;
                  break;
                default: break;
              };
              break;
            case 12:
              switch (data1)
              {
                case 0x0C:
                  data1 = 0x24;
                  channel = 4;
                  break;
                default: break;
              };
              break;
            default: break;
          };
        };
        break;
      case midi::ProgramChange:
        switch (channel)
        {
          case 1:
          case 6:
          case 7:
          case 8:
          case 9:
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
            break;
          case 2:
            data1 = 61 - 1; //French Horn
            break;
          case 3:
            data1 = 43 - 1; //Cello
            break;
          case 4:
            data1 = 48 - 1; //Timpani
            break;
          case 5:
            data1 = 76 - 1; //Pan Flute
            break;
          case 10:
            midiA.send(midi::ControlChange,0,121,10);
            midiA.send(midi::ControlChange,0x20,3,10);
            data1 = 128 - 1;  //Explosion
            break;
          default: break;
        };
        break;
      default: break;
    };
    // Thru on A has already pushed the input message to out A.
    // Forward the message to out B as well.
    midiA.send(type, data1, data2, channel);
  }
#endif

}

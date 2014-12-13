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
            case 0x2:  switch (data1)
              {
                case 0x37:
                  data1 = 0x2B;
                  channel = 0x2;
                  break;
                case 0x48:
                  data1 = 0x3C;
                  channel = 0x2;
                  break;
                case 0x52:
                  data1 = 0x46;
                  channel = 0x2;
                  break;
                case 0x60:
                  data1 = 0x54;
                  channel = 0x5;
                  break;
                default: break;
              };
              break;
            case 0x3:  switch (data1)
              {
                case 0x18:
                  data1 = 0x0C;
                  channel = 0x2;
                  break;
                case 0x37:
                  data1 = 0x2A;
                  channel = 0x3;
                  break;
                case 0x3C:
                  data1 = 0x30;
                  channel = 0x3;
                  break;
                case 0x48:
                  data1 = 0x3C;
                  channel = 0x3;
                  break;
                default: break;
              };
              break;
            case 0x4:  switch (data1)
              {
                case 0x11:
                  data1 = 0x04;
                  channel = 0x4;
                  break;
                case 0x13:
                  data1 = 0x07;
                  channel = 0x4;
                  break;
                case 0x24:
                  data1 = 0x18;
                  channel = 0x4;
                  break;
                case 0x30:
                  data1 = 0x24;
                  channel = 0x5;
                  break;
                default: break;
              };
              break;
            case 0x5:  switch (data1)
              {
                case 0x30:
                  data1 = 0x24;
                  channel = 0x3;
                  break;
                case 0x3E:
                  data1 = 0x32;
                  channel = 0x5;
                  break;
                case 0x4E:
                  data1 = 0x42;
                  channel = 0x5;
                  break;
                default: break;
              };
              break;
            case 0xC:
              switch (data1)
              {
                case 0x0C:
                  data1 = 0x00;
                  channel = 0x4;
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
          case 5:
            data1 = 75;
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

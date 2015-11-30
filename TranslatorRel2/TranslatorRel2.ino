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
  if (midiA.read())
  {
    type = midiA.getType();
    data1 = midiA.getData1();
    data2 = midiA.getData2();
    channel = midiA.getChannel();
    switch (type)
    {
      case midi::NoteOff:
        if (data2 != 0x00) break;
      case midi::NoteOn:
        if (data2 != 0x6E) break;
        {
          switch (channel)
          {
            case 1:  switch	(data1)
              {
                case 0x28:
                case 0x30:
                case 0x37:
                case 0x3C:
                case 0x40:
                case 0x43:
                case 0x45:
                case 0x48:
                case 0x4C:
                case 0x4E:
                case 0x4F:
                case 0x50:
                case 0x52:
                  midiA.send(type, data1, data2, channel);
                default:
                  break;
              };
              break;
            case 2:  switch (data1)
              {
                case 0x37:
                  data1 = 0x2B;
                  channel = 2;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x48:
                  data1 = 0x3C;
                  channel = 2;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x52:
                  data1 = 0x18;
                  channel = 10;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x60:
                  data1 = 0x54;
                  channel = 5;
                  midiA.send(type, data1, data2, channel);
                  break;
                default: break;
              };
              break;
            case 3:  switch (data1)
              {
                case 0x18:
                  data1 = 0x18;
                  channel = 2;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x37:
                  data1 = 0x2B;
                  channel = 3;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x3C:
                  data1 = 0x30;
                  channel = 3;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x48:
                  data1 = 0x3C;
                  channel = 3;
                  midiA.send(type, data1, data2, channel);
                  break;
                default: break;
              };
              break;
            case 4:  switch (data1)
              {
                case 0x11:
                  data1 = 0x28;
                  channel = 4;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x13:
                  data1 = 0x2B;
                  channel = 4;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x24:
                  data1 = 0x30;
                  channel = 4;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x30:
                  data1 = 0x24;
                  channel = 5;
                  midiA.send(type, data1, data2, channel);
                  break;
                default: break;
              };
              break;
            case 5:  switch (data1)
              {
                case 0x30:
                  data1 = 0x24;
                  channel = 3;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x3E:
                  data1 = 0x32;
                  channel = 5;
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x4E:
                  data1 = 0x42;
                  channel = 5;
                  midiA.send(type, data1, data2, channel);
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
                  midiA.send(type, data1, data2, channel);
                  break;
                case 0x28:
                case 0x30:
                case 0x37:
                case 0x3C:
                  midiA.send(type, data1, data2, channel);
                default: break;
              };
              break;
            case 6:  switch	(data1)
              {
                case 0x30:
                case 0x37:
                case 0x3C:
                case 0x40:
                case 0x43:
                case 0x45:
                case 0x48:
                case 0x4A:
                case 0x4C:
                case 0x4F:
                  midiA.send(type, data1, data2, channel);
                default:
                  break;
              };
              break;
            case 7:  switch	(data1)
              {
                case 0x28:
                case 0x37:
                case 0x3C:
                case 0x40:
                case 0x43:
                case 0x45:
                case 0x48:
                case 0x4A:
                  midiA.send(type, data1, data2, channel);
                default:
                  break;
              };
              break;
            case 8:  switch	(data1)
              {
                case 0x30:
                case 0x37:
                case 0x3C:
                case 0x40:
                case 0x45:
                case 0x48:
                case 0x4E:
                  midiA.send(type, data1, data2, channel);
                default:
                  break;
              };
              break;
            case 9:  switch	(data1)
              {
                case 0x28:
                case 0x30:
                case 0x3C:
                case 0x40:
                  midiA.send(type, data1, data2, channel);
                default:
                  break;
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
            midiA.send(type, data1, data2, channel);
            break;
          case 2:
            data1 = 61 - 1; //French Horn
            midiA.send(type, data1, data2, channel);
            break;
          case 3:
            data1 = 43 - 1; //Cello
            midiA.send(type, data1, data2, channel);
            break;
//          case 4:
//            data1 = 48 - 1; //Timpani
//            midiA.send(type, data1, data2, channel);
//            break;
          case 5:
            data1 = 76 - 1; //Pan Flute
            midiA.send(type, data1, data2, channel);
            break;
          case 10:
            midiA.send(midi::ControlChange, 0, 121, 10);
            midiA.send(midi::ControlChange, 0x20, 3, 10);
            data1 = 128 - 1;  //Explosion
            midiA.send(type, data1, data2, channel);
            break;
          default: break;
        };
        break;
      default: break;
    };
  };
}


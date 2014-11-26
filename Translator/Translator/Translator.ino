#include <MIDI.h>
byte newNote, newChannel;


    MIDI_CREATE_INSTANCE(HardwareSerial, Serial,     midiA);

void setup()
{
    // Initiate MIDI communications, listen to all channels
    midiA.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
    if (midiA.read())
    {
      note=midiA.getData1();
      channel=getChannel());
      switch (channel)
      {
        case 0:  switch (note)
                  {
                    case 0:
                    default: break;
                    }
        default: break
        }
        // Thru on A has already pushed the input message to out A.
        // Forward the message to out B as well.
        midiB.send(midiA.getType(),
                   midiA.newNote,
                   midiA.getData2(),
                   midiA.newChannel;
    }

}

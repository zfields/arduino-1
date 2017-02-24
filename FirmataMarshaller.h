/*
  Firmata.h - Firmata library v2.5.4 - 2016-10-23
  Copyright (c) 2006-2008 Hans-Christoph Steiner.  All rights reserved.
  Copyright (C) 2009-2016 Jeff Hoefs.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

#ifndef FirmataMarshaller_h
#define FirmataMarshaller_h

#if defined(__cplusplus) && !defined(ARDUINO)
  #include <cstddef>
  #include <cstdint>
#else
  #include <stddef.h>
  #include <stdint.h>
#endif

#include <Stream.h>

class FirmataMarshaller
{
  friend class FirmataClass;
  public:
    typedef uint8_t (*pinToAnalogFunction)(size_t pin);

    /* constructors */
    FirmataMarshaller(
        const pinToAnalogFunction pinToAnalog
    );

    /* public methods */
    void begin(Stream &s);
    void end();

    /* serial send handling */
    void reportAnalogDisable(uint8_t pin) const;
    void reportAnalogEnable(uint8_t pin) const;
    void reportDigitalPortDisable(uint8_t portNumber) const;
    void reportDigitalPortEnable(uint8_t portNumber) const;
    void sendAnalog(uint8_t pin, uint16_t value) const;
    void sendAnalogMappingQuery(void) const;
    void sendCapabilityQuery(void) const;
    void sendDigital(uint8_t pin, uint8_t value) const;
    void sendDigitalPort(uint8_t portNumber, uint16_t portData) const;
    void sendPinMode(uint8_t pin, uint8_t config) const;
    void sendString(const char *string) const;
    void sendSysex(uint8_t command, size_t bytec, uint8_t *bytev) const;

  private:
    /* utility methods */
    void reportAnalog(uint8_t pin, bool stream_enable) const;
    void reportDigitalPort(uint8_t portNumber, bool stream_enable) const;
    void sendValueAsTwo7bitBytes(uint16_t value) const;

    Stream * FirmataStream;
    const pinToAnalogFunction pinToAnalog;
};

#endif /* FirmataMarshaller_h */


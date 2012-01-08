# RM4: An RF Remote library for Arduino

RM4 is a library for interfacing with 4-channel RF receivers, like the
[RM4SG-M](http://www.e-madeinchn.com/ReceiverModules.html). These receivers are
paired with 4-button keyfobs.

The RM4 library provides a class, `RM4`, that provides a convenient interface
for translating the four data pins into a 4-bit button code. An example,
*show_buttons.pde*, is provided to demonstate how to use RM4.

The module on which RM4 is based, and the configuration in which the example is
run, is shown in the picture below.

![RF module with Arduino](http://farm8.staticflickr.com/7031/6658909747_cc25ee6cd1.jpg)

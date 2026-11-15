# Sonoff POW Elite — TinyC Slim device templates

The shared firmware environment is \`tasmota32-ottelo-pow-slim\`. Both models use the
CSE7766 energy monitor on GPIO16 and the TM1621 display on GPIO14/25/26/27.
Only the relay GPIO assignment differs.

## POWR316D — 16 A

- GPIO13: Relay 1
- GPIO16: CSE7766 RX
- GPIO14: TM1621 DAT
- GPIO25: TM1621 CS
- GPIO26: TM1621 RD
- GPIO27: TM1621 WR

Template JSON:

\`\`\`json
{"NAME":"Sonoff POWR316D","GPIO":[32,0,0,0,0,576,0,0,0,224,9280,0,3104,0,320,0,0,0,0,0,0,9184,9248,9216,0,0,0,0,0,0,0,0,0,0,0,0],"FLAG":0,"BASE":1}
\`\`\`

## POWR320D — 20 A

- GPIO2: Relay_b 2
- GPIO4: Relay_b 1
- GPIO16: CSE7766 RX
- GPIO14: TM1621 DAT
- GPIO25: TM1621 CS
- GPIO26: TM1621 RD
- GPIO27: TM1621 WR

Template JSON:

\`\`\`json
{"NAME":"Sonoff POWR320D","GPIO":[32,0,9313,0,9312,576,0,0,0,0,9280,0,3104,0,320,0,0,0,0,0,0,9184,9248,9216,0,0,0,0,0,0,0,0,0,0,0,0],"FLAG":0,"BASE":1}
\`\`\`

Both templates are based on the published Blackadder device definitions:
- https://templates.blakadder.com/sonoff_POWR316D.html
- https://templates.blakadder.com/sonoff_POWR320D.html

The firmware includes \`USE_CSE7766\` and \`USE_DISPLAY_TM1621_SONOFF\`; it deliberately does
not include BL0942, SML, Berry, the classic Scripter, timers or sunrise/sunset support.
The standard Tasmota environments are unaffected because every override is guarded by
\`OTTELLO_POW_SLIM\`.

After flashing, select/import the matching template for the physical model and calibrate
the energy measurement against a trusted meter.

#include <pgmspace.h>
 
#define SECRET
 
const char WIFI_SSID[] = "Fibertel WiFi252";               //TAMIM2.4G
const char WIFI_PASSWORD[] = "01534982576";           //0544287380
 
#define THINGNAME "ESP8266"
 
int8_t TIME_ZONE = -3; //NYC(USA): -5 UTC
 
const char MQTT_HOST[] = "a21k3b15l5t079-ats.iot.us-east-1.amazonaws.com";

 
 
static const char cacert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
 
// Copy contents from XXXXXXXX-certificate.pem.crt here ▼
static const char client_cert[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAKORGJUiLMqW4d20lA0wq37gWh2AMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzA2MTUxOTQ3
NDJaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDVSCEo6MEii4+/Eh/Q
MAmBIKevTwXfccCz11TpA0961lLYRgIVzSBOMbdr/qjrfSOI2M7wzLkkVX4YIPOj
p2RCgdoltCHCxpH1VuFw3Q4aIm/0W7z+qwTK3lSRccvLoxeGM0jhFe+gvX5y8o8k
7/MrO7VbjRnXzZT5FisvD3OeVf7NtXnnwlCPMW6AqIAlU1Jmah3rhq2X+zJbef6S
DI0jxsOZGQuHsp1H8r9Jke0DzxyAwulGQoM4b+KoZBEsloO253YWLw2OQKb0SrXc
YZc0iCalLCoRNRVHsfwAaCiSpbnZjHPcoTmmvODQY1Pz/ufwnUAxyxl/eOXbNyIk
zHD1AgMBAAGjYDBeMB8GA1UdIwQYMBaAFJi/vm5ImSDthJ84lSAfnx9G5UgLMB0G
A1UdDgQWBBQOGnA5X0tMGgFYv/IqYMvjs2ZaujAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAg1nZS90Sy2GvxbBtn0i4P2gM
VyfGkGBlXaIa3gEI0tzNIH0Omfp6mlFb+uCAjnOukMOpWLcdy3Um0kSDGizdMGQD
sEQZ9tyEuU9RJk8w8wc6BckuI8uYMpXo6Y8ncVvZe3qIIUg9nOjB3OX6oBpD38Vc
D/77fJ4BlUZgDUlclRUtHVpmow+ghsdGb0ysw3GiB42/0GkkPVE/7FfwmmsDxPNC
Qz8BPJeZwNKOsGSDcCgBpNQyodK2YTxNRi97v7mzfsujZ1dNHU1s8fN+4JKSUO0G
ksfD+0JyNpKYV69pOtgZoP+0uDmgtKJ8XviG9xXjaDAB+/YCBL8BuaY6NV4lzg==
-----END CERTIFICATE-----
 
)KEY";
 
 
// Copy contents from  XXXXXXXX-private.pem.key here ▼
static const char privkey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEA1UghKOjBIouPvxIf0DAJgSCnr08F33HAs9dU6QNPetZS2EYC
Fc0gTjG3a/6o630jiNjO8My5JFV+GCDzo6dkQoHaJbQhwsaR9VbhcN0OGiJv9Fu8
/qsEyt5UkXHLy6MXhjNI4RXvoL1+cvKPJO/zKzu1W40Z182U+RYrLw9znlX+zbV5
58JQjzFugKiAJVNSZmod64atl/syW3n+kgyNI8bDmRkLh7KdR/K/SZHtA88cgMLp
RkKDOG/iqGQRLJaDtud2Fi8NjkCm9Eq13GGXNIgmpSwqETUVR7H8AGgokqW52Yxz
3KE5przg0GNT8/7n8J1AMcsZf3jl2zciJMxw9QIDAQABAoIBAQCc5lcelTufgjPZ
SCgHK4+SYsd4/BVB75jntD1OvZS2tPx1Bet6xlBBtelNlSYHNyPxBC4Yj0KULCB6
96LEfdwP4R7uJbnAY/v0FFn8gWJib3sUtHgwkPcRlsV3ydM2l2Ay5X9ztoN2KHDh
dvc/IRYuc9pS41Zjn2U8aMaT9DYF/71LTTZFUwEphpG85vs+lWxaMjSOfLWEjiPC
k9r+9Palh+hZUcOYbh8Qv3rLadsTnR9OVPtd7eDAx5xALM9pa3P+15xY4SiQl3Sr
/YRpS8RNi2mwrt2fAk+1+WRGckR+uhTbFFLmgxedoVjjjhi50IeJ/LHU3GP+wNY8
hTi09T+BAoGBAPK4koxfv8BKsRVelJbwbYBGIZpARBkjaAj/gnsi2ozmvu0Ff8Zi
UzfOh9q/5UjsyWLQf7uoFTGgVrbTG00qQ58d2X/b6x1Pph4ucd7IF33GLWDRvepy
COdNq3c5F7Eb1/MWUyIQVCeiwMBSa8wx6UiKnznydNgcVWqGhfUsIseNAoGBAODz
Pv+HaJXEC8+RSLueSOM515G0YugMJFUArnDrd86GUI1mXljH6Nx8QAimntJysOvx
sypJ/4iG1CMltnLiLFXw5z8ZCez24K6EtwvCc952k2bB3NSbad2wksXFuqYO7cle
b6PEft2ik0Z2qnjI5UuoqXMXetNJPkJxtUokk2EJAoGAcV3IBQyLsTKxtztvx3gQ
jQM0mqk9pUgmRV2iAgVrcrgroOUaovw1xjEOvxs16nO+NAsSPgHptD4hgk7jx4zf
/KeieNes3wnemuYyhU2Lu1EezMPqImCUzAQ4+/yMlkpc+MsKlTRvOfwIb0uP0dXW
Ee29JQGblXzWYGTomHS+4dkCgYEA0NI+OyvSdKUnaaqu4CxR8U3yxbm0z0DmQVp+
lSihcUDSalELaFM74eId92nlqer6Pi2DatCCvJSdPXt24TMAgU8+/B4cTrPnY1qk
KfB7a5qbvxpcC6myHzAZMCsb16eoKfTWoip4svqGyTTDj5i+8vtBQiwbwyQM/dVc
u9U0UzECgYEA2gElxA8VqWMZXc9WCIrg/oFToAD8mQFt1zl/sr2VGr6Kk4gN0CoA
MAtBeUDFVoVg3aVa+uJMk1cyZQNKiQ5Am9H3Wj+Y4oB02FO4m20ybBFbWC1PgIb5
szIC0/yDlrrinGy2KQ0l5a1c4E/+99b6TfY6PDSyU5eyaWJAETaG0Ic=
-----END RSA PRIVATE KEY-----
 
)KEY";
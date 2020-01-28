# WPILib Wrapper

This directory contains the source for the shared libraries created to directly call functions in the LabVIEW toolkit. Some of the WPILib functions had to be pulled in directly to avoid linking to the WPILib HAL. This **cannot** link to the wpilib HAL or it will break LabVIEW.

TODO: Build roboRIO binaries. The output .so file can be copied to a folder in C:\Program Files (x86)\National Instruments\LabVIEW 2019\vi.lib\addons\FRC_ThirdParty\lib see the readme in that folder for detals.

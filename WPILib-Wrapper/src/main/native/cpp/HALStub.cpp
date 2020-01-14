#if 0
#include <stdint.h>

extern "C" {

typedef int32_t HAL_Bool;
typedef int32_t HAL_ControlWord;
typedef int32_t HAL_AllianceStationID;
typedef int32_t HAL_JoystickAxes;
typedef int32_t HAL_JoystickPOVs;
typedef int32_t HAL_JoystickButtons;
typedef int32_t HAL_JoystickDescriptor;
typedef int32_t HAL_MatchInfo;

int32_t HAL_SendError(HAL_Bool a, int32_t errorCode, HAL_Bool isLVCode) {
    (void)a;
    (void)errorCode;
    (void)isLVCode;
    return 0;
}

int32_t HAL_GetControlWord(HAL_ControlWord* controlWord) {
    (void)controlWord;
    return 0;
}

HAL_AllianceStationID HAL_GetAllianceStation(int32_t* status) {
    (void)status;
    return 0;
}

int32_t HAL_GetJoystickAxes(int32_t joystickNum, HAL_JoystickAxes* axes) {
    (void)joystickNum;
    (void)axes;
    return 0;
}

int32_t HAL_GetJoystickPOVs(int32_t joystickNum, HAL_JoystickPOVs* povs) {
    (void)joystickNum;
    (void)povs;
    return 0;
}

int32_t HAL_GetJoystickButtons(int32_t joystickNum,
                               HAL_JoystickButtons* buttons) {
    (void)joystickNum;
    (void)buttons;
    return 0;                          
}

int32_t HAL_GetJoystickDescriptor(int32_t joystickNum,
                                  HAL_JoystickDescriptor* desc) {
    (void)joystickNum;
    (void)desc;
    return 0;
}

double HAL_GetMatchTime(int32_t* status) {
    (void)status;
    return 0.0;
}

int32_t HAL_GetMatchInfo(HAL_MatchInfo* info) {
    (void)info;
    return 0;
}

void HAL_ReleaseDSMutex(void) {

}

HAL_Bool HAL_IsNewControlData(void) {
    return 0;
}

void HAL_WaitForDSData(void) {

}
void HAL_ObserveUserProgramDisabled(void) {

}
void HAL_ObserveUserProgramAutonomous(void) {

}
void HAL_ObserveUserProgramTeleop(void) {

}
void HAL_ObserveUserProgramTest(void) {

}

HAL_Bool HAL_Initialize(int32_t timeout, int32_t mode) {
    (void)timeout;
    (void)mode;
    return 0;
}

double HAL_GetVinVoltage(int32_t* status) {
    (void)status;
    return 0.0;
}

void HAL_CAN_GetCANStatus(float* percentBusUtilization, uint32_t* busOffCount,
                          uint32_t* txFullCount, uint32_t* receiveErrorCount,
                          uint32_t* transmitErrorCount, int32_t* status) {
    (void)percentBusUtilization;
    (void)busOffCount;
    (void)txFullCount;
    (void)receiveErrorCount;
    (void)transmitErrorCount;
    (void)status;
}

const char* HAL_GetErrorMessage(int32_t code) {
    (void)code;
    return "";
}
int32_t HAL_GetFPGAVersion(int32_t* status) {
    (void)status;
    return 0;
}
int64_t HAL_GetFPGARevision(int32_t* status) {
    (void)status;
    return 0;
}
HAL_Bool HAL_GetFPGAButton(int32_t* status) {
    (void)status;
    return 0;
}
HAL_Bool HAL_GetSystemActive(int32_t* status) {
    (void)status;
    return 0;
}
HAL_Bool HAL_GetBrownedOut(int32_t* status) {
    (void)status;
    return 0;
}
uint64_t HAL_GetFPGATime(int32_t* status) {
    (void)status;
    return 0;
}
double HAL_GetVinCurrent(int32_t* status) {
    (void)status;
    return 0.0;
}
double HAL_GetUserVoltage6V(int32_t* status) {
    (void)status;
    return 0.0;
}
double HAL_GetUserCurrent6V(int32_t* status) {
    (void)status;
    return 0.0;
}
HAL_Bool HAL_GetUserActive6V(int32_t* status) {
    (void)status;
    return 0;
}
int32_t HAL_GetUserCurrentFaults6V(int32_t* status) {
    (void)status;
    return 0;
}
double HAL_GetUserVoltage5V(int32_t* status) {
    (void)status;
    return 0.0;
}
double HAL_GetUserCurrent5V(int32_t* status) {
    (void)status;
    return 0.0;
}
HAL_Bool HAL_GetUserActive5V(int32_t* status) {
    (void)status;
    return 0;
}
int32_t HAL_GetUserCurrentFaults5V(int32_t* status) {
    (void)status;
    return 0;
}
double HAL_GetUserVoltage3V3(int32_t* status) {
    (void)status;
    return 0.0;
}
double HAL_GetUserCurrent3V3(int32_t* status) {
    (void)status;
    return 0.0;
}
HAL_Bool HAL_GetUserActive3V3(int32_t* status) {
    (void)status;
    return 0;
}
int32_t HAL_GetUserCurrentFaults3V3(int32_t* status) {
    (void)status;
    return 0;
}

} // extern "C"

#include <memory>
#include <wpi/Twine.h>

enum NT_Type {
  NT_UNASSIGNED = 0
};

namespace nt {

    class NetworkTable;

    class Value {
        struct private_init {};
    public:
        Value(void) { }
        Value(NT_Type a, uint64_t b, const private_init& c) {
            (void)a;
            (void)b;
            (void)c;
        }
        ~Value(void) { }
    };

    class NetworkTableEntry {
    public:
        std::shared_ptr<NetworkTable> GetTable(class wpi::Twine const & a)const {
            (void)a;
            return std::make_shared<NetworkTable>();
        }
    };

    class NetworkTable {
    public:
        NetworkTableEntry GetEntry(wpi::Twine const & a) const {
            (void)a;
            return NetworkTableEntry();
        }
    };

    class NetworkTableInstance {
    public:
        std::shared_ptr<NetworkTable> GetTable(wpi::Twine const & a)const {
            (void)a;
            return std::make_shared<NetworkTable>();
        }
    };

    unsigned int GetDefaultInstance(void) {
        return 0;
    }

    bool SetEntryValue(unsigned int a, std::shared_ptr<Value> b) {
        (void)a;
        (void)b;
        return false;
    }

    void SetEntryTypeValue(unsigned int a, std::shared_ptr<Value> b) {
        (void)a;
        (void)b;
    }
} // namespace nt
#endif

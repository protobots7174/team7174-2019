#include <cmath>
#include "ctre/Phoenix.h"
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedController.h>
#include <frc/Talon.h>
#include "MyPID.h"

#define TALON_DRIVE_LF 2
#define TALON_DRIVE_LR 1
#define TALON_DRIVE_RF 4
#define TALON_DRIVE_RR 3
#define DRIVE_ENCODER_COUNTS_PER_FOOT 535.0

class Drivetrain {

public:
Drivetrain();
void ArcadeDrive(double speed, double angle);

double getDistance();
double getRDistance();
double getLDistance();
double getRVelocity();
double getLVelocity();
double getYaw();


void resetEncoders();
void encoderWrite(double rightDistance, double leftDistance);
bool autonDrivetrain(double rVelocity, double lVelocity, double rDistance, double lDistance);
double velocityMultiplier(double firstV, double secondV, double firstEncoderSpeed, double secondEncoderSpeed);
bool autonLimeDrive(double speed, double angle, double area);
double pidDrive(double angle, double distance);
bool autonTurning(double distance);
double getTurningDistance();
bool autonStraight(double distance);
bool autonPID(double distance);

protobot::ProtoPID m_drivePID;

private:
WPI_TalonSRX  m_lDriveF;
WPI_TalonSRX  m_lDriveR;
WPI_TalonSRX  m_rDriveF;
WPI_TalonSRX  m_rDriveR;
frc::SpeedControllerGroup m_lSpeedGroup;
frc::SpeedControllerGroup m_rSpeedGroup;
frc::DifferentialDrive m_drive;
PigeonIMU pidgey;
double xyz[3];

//Robot m_robot;
};
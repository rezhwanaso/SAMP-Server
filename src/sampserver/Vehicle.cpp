#include "Vehicle.h"
#include "VehicleDamageStatus.h"

Vehicle::Vehicle(int model, float x, float y, float z, float rotation, int color1, int color2, int respawnDelay, std::string licensePlate)
{
	id_ = Vehicle::samp_Create(model, x, y, z, rotation, color1, color2, respawnDelay);
	this->samp_SetNumberPlate(licensePlate.c_str());
	model_ = model;
	x_ = x;
	y_ = y;
	z_ = z;
	rotation_ = rotation;
	color1_ = color1;
	color2_ = color2;
	respawnDelay_ = respawnDelay;
	licensePlate_ = licensePlate;
	damageStatus_ = new VehicleDamageStatus(1000, 0, 0, 0, 0);
}

Vehicle::~Vehicle()
{
}

void Vehicle::setDamage(float health, int panels, int doors, int lights, int tires)
{
	damageStatus_->UpdateStatus(health, panels, doors, lights, tires);
	samp_UpdateDamageStatus(panels, doors, lights, tires);
	samp_SetHealth(health);
}

void Vehicle::setHealth(float health)
{
	setDamage(health, damageStatus_->getPanelsRaw(), damageStatus_->getDoorsRaw(), damageStatus_->getLightsRaw(), damageStatus_->getTiresRaw());
}

void Vehicle::setVirtualWorld(int virtualWorld)
{
	this->samp_SetVirtualWorld(virtualWorld);
}

void Vehicle::LinkToInterior(int interior)
{
	this->samp_LinkToInterior(interior);
}

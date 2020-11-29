/**
 * \file AnimalChannelAngle.h
 *
 * \author Andrew Decrem
 *
 * Angle of the animated channel
 */
#pragma once
#include "AnimChannel.h"
/**
 * Animation channel for angles.
 */
class CAnimChannelAngle : public CAnimChannel
{
public:
    ///Constructor
    CAnimChannelAngle();
    ///destructor
    virtual ~CAnimChannelAngle();

    ///disable copy constructor
    CAnimChannelAngle(const CAnimChannelAngle&) = delete;
    ///disable assignment
    void operator=(const CAnimChannelAngle&) = delete;
    ///get the angle
    double GetAngle() { return mAngle; }
    ///set key frame
    void SetKeyframe(double angle);
    ///Keyframe class
    class KeyframeAngle : public CAnimChannel::Keyframe
    {
        /** Constructor
         * \param channel The channel we are for
         * \param angle The angle for the keyframe */
        KeyframeAngle(CAnimChannelAngle* channel, double angle) :
            Keyframe(channel), mChannel(channel), mAngle(angle) {}
        ///disable default
        KeyframeAngle() = delete;
        ///Disable copy
        KeyframeAngle(const KeyframeAngle&) = delete;
        ///Disable assignment
        void operator=(const KeyframeAngle&) = delete;

        double GetAngle() { return mAngle; }
        ///Use functions
        virtual void UseAs1() override { mChannel->mKeyframe1 = this; }
        virtual void UseAs2() override { mChannel->mKeyframe2 = this; }
        virtual void UseOnly() override { mChannel->mAngle = mAngle; }

    private:
        ///angle
        double mAngle = 0;
        ///channel
        CAnimChannelAngle* mChannel;
    };
protected:
    void Tween(double t);
private:
    double mAngle = 0; ///< angle set to 0 default
    KeyframeAngle* mKeyframe1 = nullptr; ///< first
    KeyframeAngle* mKeyframe2 = nullptr; ///< seconds
};


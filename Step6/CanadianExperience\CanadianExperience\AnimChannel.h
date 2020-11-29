/**
 * \file AnimChannel.h
 *
 * \author Andrew Decrem
 *
 * The main animated channel
 */
#pragma once
#include <string>
#include <memory>
#include <vector>
class CTimeline;

/** Base class for animation channels
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels. */
class CAnimChannel
{
public:
    ///constructor
    CAnimChannel();
    ///destructor
    virtual ~CAnimChannel();
    ///disable copy
    CAnimChannel(const CAnimChannel&) = delete;
    ///disable assignment
    void operator=(const CAnimChannel&) = delete;
    ///setter for name
    void SetName(const std::wstring& name) { mName = name; }
    ///getter for  name
    std::wstring GetName() const { return mName; }
    ///setter for timeline
    void SetTimeline(CTimeline* timeline) { mTimeline = timeline; }
    ///getter for timeline
    CTimeline* GetTimeline() { return mTimeline; }

    //Isvalid function
    bool IsValid();
    ///Frame setter
    void SetFrame(int currFrame);
    ///Delete keyframe
    void DeleteKeyframe();

    /** Class that represents a keyframe */
    class Keyframe
    {
    public:
        ///default disable
        Keyframe() = delete;
        ///copy disable
        Keyframe(const Keyframe&) = delete;
        ///assignment disable
        void operator=(const Keyframe&) = delete;
        ///set frame
        void SetFrame(const int frame) { mFrame = frame; }
        ///getter for frame
        int GetFrame() const { return mFrame; }
        //virtual use as functions found in given files
        virtual void UseAs1() = 0;
        virtual void UseAs2() = 0;
        virtual void UseOnly() = 0;
    protected:
        ///frame
        int mFrame;
        ///Keyframe
        Keyframe(CAnimChannel* channel) : mChannel(channel) {}
    private:
        ///Channel definition
        CAnimChannel* mChannel;
    };
protected:
    ///provided tween
    virtual void Tween(double t) = 0;
    ///Insert the keyframe
    void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);
private:
    std::wstring mName;     ///< The channel name
    int mKeyframe1 = -1;    ///< The first keyframe
    int mKeyframe2 = -1;    ///< The second keyframe
    CTimeline* mTimeline = nullptr; ///< timeline
    std::vector < std::shared_ptr<Keyframe>> mKeyframes; ///< keyframes
};

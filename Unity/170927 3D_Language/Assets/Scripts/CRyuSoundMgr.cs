using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System.Xml;
using System;

public class CRyuSoundMgr{

    private static CRyuSoundMgr mInstance = null;
    private CAudioBundle mpAudioBundle = null;
    private List<AudioSource> mAudioArray = null;

    protected CRyuSoundMgr()
    {
        mInstance = null;
    }

    public static CRyuSoundMgr GetInst()
    {
        if(mInstance == null)
        {
            mInstance = new CRyuSoundMgr();
        }

        return mInstance;
    }

    public void CreateRyu()
    {
        mAudioArray = new List<AudioSource>();
    }

    public void DestroyRyu()
    {

    }

    public void SetAudioBundle (CAudioBundle tBundle)

    {
        mpAudioBundle = tBundle;
        GameObject.DontDestroyOnLoad(mpAudioBundle);
        //씬이 바뀌어도 소멸하지 말아라
    }

    public void BuildRyu()
    {
        int ti = 0;
        int tCount = mpAudioBundle.mArray.Length;

        for(ti =0; ti < tCount; ti ++ )
        {
            mAudioArray.Add(mpAudioBundle.mArray[ti]);
        }
    }

    public void Play(int tIndex)
    {
        int tCount = mpAudioBundle.mArray.Length;
        if(tIndex < tCount)
        {
            mAudioArray[tIndex].Play();
        }
    }

    public void Stop(int tIndex)
    {
        int tCount = mpAudioBundle.mArray.Length;
        if (tIndex < tCount)
        {
            mAudioArray[tIndex].Stop();
        }
    }

    public bool IsPlaying(int tIndex)
    {
        bool tResult = false;

        if(tIndex < 0)
        {
            return tResult;
        }
        if(tIndex>mAudioArray.Count -1)
        {
            return tResult;
        }

        tResult = mAudioArray[tIndex].isPlaying;

        return tResult;
    }

    public void DoSoundOff()
    {
        if (null == mAudioArray)
        {
            return;
        }

        int ti = 0;
        int tCount = 0;
        AudioSource tAS = null;

        tCount = mAudioArray.Count;

        for (ti = 0; ti < tCount; ti++)
        {
            tAS = null;
            tAS = mAudioArray[ti];
            tAS.mute = true;
        }
    }


    public void DoSoundOn()
    {
        if (null == mAudioArray)
        {
            return;
        }

        int ti = 0;
        int tCount = 0;
        AudioSource tAS = null;

        tCount = mAudioArray.Count;

        for (ti = 0; ti < tCount; ti++)
        {
            tAS = null;
            tAS = mAudioArray[ti];
            tAS.mute = false;
        }
    }


    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}

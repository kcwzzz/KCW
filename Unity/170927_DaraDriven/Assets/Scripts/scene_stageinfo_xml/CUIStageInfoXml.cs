using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System.Xml;
using System;

using UnityEngine.UI;

public class CUIStageInfoXml : MonoBehaviour {

    public Text mpTxtString = null;

    public CRyuStageInfoList mStageInfoBundle = null;

    // Use this for initialization
    void Start () {
        mStageInfoBundle = new CRyuStageInfoList(); 
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    public void OnClickBtnLoadFromXmlFile()
    {
        LoadFromXmlFile("stage_info_xml");
    }

    protected bool LoadFromXmlFile(string tFileName)
    {
        TextAsset tTextAsset = null;
        tTextAsset = Resources.Load<TextAsset>(tFileName) as TextAsset;

        if(null == tTextAsset)
        {
            return false;
        }

        mpTxtString.text = tTextAsset.text;

        XmlDocument tDoc = new XmlDocument();
        tDoc.LoadXml(tTextAsset.text);

        CRyuStageInfo tStageInfo = null;
        CRyuUnitInfo tUnitINfo = null;

        XmlElement tElementRoot = tDoc["response"];

        mStageInfoBundle.mStageInfoList = new List<CRyuStageInfo>();

        foreach(XmlElement tElementStageInfoList in tElementRoot.ChildNodes)
        {
            foreach(XmlElement tElementStageInfo in tElementStageInfoList.ChildNodes)
            {
                tStageInfo = null;
                tStageInfo = new CRyuStageInfo();

                tStageInfo.mId              = System.Convert.ToInt32(tElementStageInfo.ChildNodes[0].InnerText);
                tStageInfo.mTotalEnemyCount = System.Convert.ToInt32(tElementStageInfo.ChildNodes[1].InnerText);

                if(tElementStageInfo.ChildNodes[2].ChildNodes.Count>0)
                {
                    tStageInfo.mUnitInfoList = new List<CRyuUnitInfo>();
                    foreach(XmlElement tElementUnitInfo in tElementStageInfo.ChildNodes[2])
                    {
                        tUnitINfo = null;
                        tUnitINfo = new CRyuUnitInfo();

                        tUnitINfo.mX = System.Convert.ToInt32(tElementUnitInfo.ChildNodes[0].InnerText);
                        tUnitINfo.mY = System.Convert.ToInt32(tElementUnitInfo.ChildNodes[1].InnerText);

                        tStageInfo.mUnitInfoList.Add(tUnitINfo);
                    }

                }

                mStageInfoBundle.mStageInfoList.Add(tStageInfo);

            }
        }


        foreach(CRyuStageInfo tRyuStageINfo in this.mStageInfoBundle.mStageInfoList)
        {
            Debug.Log("stage_info id : "                + tRyuStageINfo.mId.ToString());
            Debug.Log("stage_info total Enemy Count : " + tRyuStageINfo.mTotalEnemyCount.ToString());

            foreach(CRyuUnitInfo tRyuUnitInfo in tRyuStageINfo.mUnitInfoList)
            {
                Debug.Log("unit_info x: " + tRyuUnitInfo.mX.ToString());
                Debug.Log("unit_info y: " + tRyuUnitInfo.mY.ToString());

            }

            Debug.Log("---------------------------------");
            

        }

        return true;
    }















}

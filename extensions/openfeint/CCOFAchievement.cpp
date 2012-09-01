
#include "CCOFAchievement.h"

NS_CC_EXT_BEGIN

CCOFAchievement* CCOFAchievement::achievementWithId(const char* id,
                                                    const char* title,
                                                    const char* description,
                                                    const char* iconUrl,
                                                    int gameScore,
                                                    bool isUnlocked,
                                                    bool isSecret)
{
    CCOFAchievement* ach = new CCOFAchievement();
    ach->m_id = id ? id : "";
    ach->m_title = title ? title : "";
    ach->m_description = description ? description : "";
    ach->m_iconUrl = iconUrl ? iconUrl : "";
    ach->m_gameScore = gameScore;
    ach->m_isUnlocked = isUnlocked;
    ach->m_isSecret = isSecret;
    ach->autorelease();
    return ach;
}

NS_CC_EXT_END

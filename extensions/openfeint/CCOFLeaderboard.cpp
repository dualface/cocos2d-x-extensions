
#include "CCOFLeaderboard.h"

NS_CC_EXT_BEGIN

CCOFLeaderboard* CCOFLeaderboard::leaderboardWithId(const char* id,
                                                    const char* name,
                                                    bool descendingScoreOrder,
                                                    int currentUserScore,
                                                    const char* currentUserScoreDisplayText)
{
    CCOFLeaderboard* board = new CCOFLeaderboard();
    board->m_id = id ? id : "";
    board->m_name = name ? name : "";
    board->m_descendingScoreOrder = descendingScoreOrder;
    board->m_currentUserScore = currentUserScore;
    board->m_currentUserScoreDisplayText = currentUserScoreDisplayText ? currentUserScoreDisplayText : "";
    board->autorelease();
    return board;
}

NS_CC_EXT_END

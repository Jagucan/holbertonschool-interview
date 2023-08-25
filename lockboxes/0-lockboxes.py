#!/usr/bin/python3
"""
Unlock Boxes
"""


def canUnlockAll(boxes):
    """
    unlock all boxes in the box system and return True if they were unlocked
    """
    unlocked = [0]
    for box_id, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < len(boxes) and key not in unlocked and key != box_id:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False

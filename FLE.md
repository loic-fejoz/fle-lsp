# Fast Log Entry (FLE) Format Documentation

Fast Log Entry (FLE) is a text-based logging format designed by DF3CB for rapid and efficient recording of amateur radio contacts.

See the original documentation at https://df3cb.com/fle/documentation/

## Document Structure

An FLE file consists of two main sections:
1. **Header Section**: Defines station info and common settings.
2. **QSO Section**: Lists individual contacts.

---

## 1. Header Section

Keywords are case-insensitive and followed by a space and their value.

| Keyword | Description | Constraints |
| :--- | :--- | :--- |
| `mycall` | Station Call Sign | **Mandatory.** One base call per file. |
| `mygrid` | Station Grid Locator | Optional. Multiple allowed (e.g., roving). |
| `operator` | Operator Call Sign | Optional. **Repeatable** for multi-op sessions. |
| `nickname` | Log Nickname | Optional. |
| `qslmsg` | Default QSL Message | Optional. |
| `mywwff` | WWFF Reference | Optional. **Strictly unique.** |
| `mysota` | SOTA Reference | Optional. **Strictly unique.** |
| `mypota` | POTA Reference | Optional. **Strictly unique.** |
| `date` | Operating Date | Format: `YYYY-MM-DD`. Multiple allowed to group QSOs. |

> [!NOTE]
> **Deviation from standard**: While strict FLE documentation suggests one `mycall` per log, this LSP allows several `mycall` declarations as long as they share the same **base callsign** (e.g., `F4JXQ`, `F4JXQ/P`, and `DL/F4JXQ` can co-exist). This allows switching between portable/mobile status in a single session. Similarly it allows several `mygrid` declarations to support roving.

---

## 2. Band and Mode Standalone Lines

You can set the band and mode for subsequent QSOs by placing them on their own line.

**Examples:**
- `40m cw` (Sets 7MHz CW)
- `20m ft8` (Sets 14MHz FT8)
- `144.300 ssb` (Sets 2m SSB)

---

## 3. QSO Line Syntax

A QSO line typically follows this structure:
`[Time] <Callsign> [RST_Sent] [RST_Received] [Extras]`

| Part | Description | Example |
| :--- | :--- | :--- |
| **Time** | 2 or 4 digits (HHMM or MM). | `1234` or `34` |
| **Callsign** | Required. The station contacted. | `G4ABC/P` |
| **RST** | Optional signal reports. | `59 55` or `599 599` |
| **Extras** | Comments, Grids, Names. | `@Bob #JN12ab [Nice OP] <QSL>` |

### Time Expansion
- If minutes are given as 2 digits, they are appended to the last known hour.
- Time is monotonic; if the new time is earlier than the previous one, it's considered an error or day change.

### Extras Syntax
- `@Name`: Contact's name.
- `#Grid`: Contact's grid locator.
- `[Comment]`: Brackets for general comments.
- `<QSL>`: Angle brackets for QSL-specific messages.
- `+`: Used as `day +` to increment the date.

---

## 4. Comments

- Lines starting with a blank space or containing only whitespace are ignored.
- Inline comments can be placed in `[]` on a QSO line.

---

## 5. Usage in LSP

The LSP implementation allows:
- **Multiple `mygrid`**: Redefining `mygrid` updates the location for subsequent contacts (useful for roving/walking).
- **Inlay Hints**: Computes distance and bearing based on the *most recent* `mygrid` set before the QSO.
- **Diagnostics**: Flags lowercase callsigns or invalid date/time formats.

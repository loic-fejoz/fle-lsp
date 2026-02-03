//nolint:revive
package flelsp

import (
	"context"

	"go.lsp.dev/protocol"
)

// UnimplementedServer provides a base implementation of protocol.Server that does nothing.
// Embed this in your handler to satisfy the interface without having to implement every method.
type UnimplementedServer struct{}

func (UnimplementedServer) Initialize(ctx context.Context, params *protocol.InitializeParams) (result *protocol.InitializeResult, err error) {
	return nil, nil
}
func (UnimplementedServer) Initialized(ctx context.Context, params *protocol.InitializedParams) (err error) {
	return nil
}
func (UnimplementedServer) Shutdown(ctx context.Context) (err error) { return nil }
func (UnimplementedServer) Exit(ctx context.Context) (err error)     { return nil }
func (UnimplementedServer) WorkDoneProgressCancel(ctx context.Context, params *protocol.WorkDoneProgressCancelParams) (err error) {
	return nil
}
func (UnimplementedServer) LogTrace(ctx context.Context, params *protocol.LogTraceParams) (err error) {
	return nil
}
func (UnimplementedServer) SetTrace(ctx context.Context, params *protocol.SetTraceParams) (err error) {
	return nil
}
func (UnimplementedServer) CodeAction(ctx context.Context, params *protocol.CodeActionParams) (result []protocol.CodeAction, err error) {
	return nil, nil
}
func (UnimplementedServer) CodeLens(ctx context.Context, params *protocol.CodeLensParams) (result []protocol.CodeLens, err error) {
	return nil, nil
}
func (UnimplementedServer) CodeLensResolve(ctx context.Context, params *protocol.CodeLens) (result *protocol.CodeLens, err error) {
	return nil, nil
}
func (UnimplementedServer) ColorPresentation(ctx context.Context, params *protocol.ColorPresentationParams) (result []protocol.ColorPresentation, err error) {
	return nil, nil
}
func (UnimplementedServer) Completion(ctx context.Context, params *protocol.CompletionParams) (result *protocol.CompletionList, err error) {
	return nil, nil
}
func (UnimplementedServer) CompletionResolve(ctx context.Context, params *protocol.CompletionItem) (result *protocol.CompletionItem, err error) {
	return nil, nil
}
func (UnimplementedServer) Declaration(ctx context.Context, params *protocol.DeclarationParams) (result []protocol.Location, err error) {
	return nil, nil
}
func (UnimplementedServer) Definition(ctx context.Context, params *protocol.DefinitionParams) (result []protocol.Location, err error) {
	return nil, nil
}
func (UnimplementedServer) DidChange(ctx context.Context, params *protocol.DidChangeTextDocumentParams) (err error) {
	return nil
}
func (UnimplementedServer) DidChangeConfiguration(ctx context.Context, params *protocol.DidChangeConfigurationParams) (err error) {
	return nil
}
func (UnimplementedServer) DidChangeWatchedFiles(ctx context.Context, params *protocol.DidChangeWatchedFilesParams) (err error) {
	return nil
}
func (UnimplementedServer) DidChangeWorkspaceFolders(ctx context.Context, params *protocol.DidChangeWorkspaceFoldersParams) (err error) {
	return nil
}
func (UnimplementedServer) DidClose(ctx context.Context, params *protocol.DidCloseTextDocumentParams) (err error) {
	return nil
}
func (UnimplementedServer) DidOpen(ctx context.Context, params *protocol.DidOpenTextDocumentParams) (err error) {
	return nil
}
func (UnimplementedServer) DidSave(ctx context.Context, params *protocol.DidSaveTextDocumentParams) (err error) {
	return nil
}
func (UnimplementedServer) DocumentColor(ctx context.Context, params *protocol.DocumentColorParams) (result []protocol.ColorInformation, err error) {
	return nil, nil
}
func (UnimplementedServer) DocumentHighlight(ctx context.Context, params *protocol.DocumentHighlightParams) (result []protocol.DocumentHighlight, err error) {
	return nil, nil
}
func (UnimplementedServer) DocumentLink(ctx context.Context, params *protocol.DocumentLinkParams) (result []protocol.DocumentLink, err error) {
	return nil, nil
}
func (UnimplementedServer) DocumentLinkResolve(ctx context.Context, params *protocol.DocumentLink) (result *protocol.DocumentLink, err error) {
	return nil, nil
}
func (UnimplementedServer) DocumentSymbol(ctx context.Context, params *protocol.DocumentSymbolParams) (result []interface{}, err error) {
	return nil, nil
}
func (UnimplementedServer) ExecuteCommand(ctx context.Context, params *protocol.ExecuteCommandParams) (result interface{}, err error) {
	return nil, nil
}
func (UnimplementedServer) FoldingRanges(ctx context.Context, params *protocol.FoldingRangeParams) (result []protocol.FoldingRange, err error) {
	return nil, nil
}
func (UnimplementedServer) Formatting(ctx context.Context, params *protocol.DocumentFormattingParams) (result []protocol.TextEdit, err error) {
	return nil, nil
}
func (UnimplementedServer) Hover(ctx context.Context, params *protocol.HoverParams) (result *protocol.Hover, err error) {
	return nil, nil
}
func (UnimplementedServer) Implementation(ctx context.Context, params *protocol.ImplementationParams) (result []protocol.Location, err error) {
	return nil, nil
}
func (UnimplementedServer) OnTypeFormatting(ctx context.Context, params *protocol.DocumentOnTypeFormattingParams) (result []protocol.TextEdit, err error) {
	return nil, nil
}
func (UnimplementedServer) PrepareRename(ctx context.Context, params *protocol.PrepareRenameParams) (result *protocol.Range, err error) {
	return nil, nil
}
func (UnimplementedServer) RangeFormatting(ctx context.Context, params *protocol.DocumentRangeFormattingParams) (result []protocol.TextEdit, err error) {
	return nil, nil
}
func (UnimplementedServer) References(ctx context.Context, params *protocol.ReferenceParams) (result []protocol.Location, err error) {
	return nil, nil
}
func (UnimplementedServer) Rename(ctx context.Context, params *protocol.RenameParams) (result *protocol.WorkspaceEdit, err error) {
	return nil, nil
}
func (UnimplementedServer) SignatureHelp(ctx context.Context, params *protocol.SignatureHelpParams) (result *protocol.SignatureHelp, err error) {
	return nil, nil
}
func (UnimplementedServer) Symbols(ctx context.Context, params *protocol.WorkspaceSymbolParams) (result []protocol.SymbolInformation, err error) {
	return nil, nil
}
func (UnimplementedServer) TypeDefinition(ctx context.Context, params *protocol.TypeDefinitionParams) (result []protocol.Location, err error) {
	return nil, nil
}
func (UnimplementedServer) WillSave(ctx context.Context, params *protocol.WillSaveTextDocumentParams) (err error) {
	return nil
}
func (UnimplementedServer) WillSaveWaitUntil(ctx context.Context, params *protocol.WillSaveTextDocumentParams) (result []protocol.TextEdit, err error) {
	return nil, nil
}
func (UnimplementedServer) ShowDocument(ctx context.Context, params *protocol.ShowDocumentParams) (result *protocol.ShowDocumentResult, err error) {
	return nil, nil
}
func (UnimplementedServer) WillCreateFiles(ctx context.Context, params *protocol.CreateFilesParams) (result *protocol.WorkspaceEdit, err error) {
	return nil, nil
}
func (UnimplementedServer) DidCreateFiles(ctx context.Context, params *protocol.CreateFilesParams) (err error) {
	return nil
}
func (UnimplementedServer) WillRenameFiles(ctx context.Context, params *protocol.RenameFilesParams) (result *protocol.WorkspaceEdit, err error) {
	return nil, nil
}
func (UnimplementedServer) DidRenameFiles(ctx context.Context, params *protocol.RenameFilesParams) (err error) {
	return nil
}
func (UnimplementedServer) WillDeleteFiles(ctx context.Context, params *protocol.DeleteFilesParams) (result *protocol.WorkspaceEdit, err error) {
	return nil, nil
}
func (UnimplementedServer) DidDeleteFiles(ctx context.Context, params *protocol.DeleteFilesParams) (err error) {
	return nil
}
func (UnimplementedServer) CodeLensRefresh(ctx context.Context) (err error) {
	return nil
}
func (UnimplementedServer) PrepareCallHierarchy(ctx context.Context, params *protocol.CallHierarchyPrepareParams) (result []protocol.CallHierarchyItem, err error) {
	return nil, nil
}
func (UnimplementedServer) IncomingCalls(ctx context.Context, params *protocol.CallHierarchyIncomingCallsParams) (result []protocol.CallHierarchyIncomingCall, err error) {
	return nil, nil
}
func (UnimplementedServer) OutgoingCalls(ctx context.Context, params *protocol.CallHierarchyOutgoingCallsParams) (result []protocol.CallHierarchyOutgoingCall, err error) {
	return nil, nil
}
func (UnimplementedServer) SemanticTokensFull(ctx context.Context, params *protocol.SemanticTokensParams) (result *protocol.SemanticTokens, err error) {
	return nil, nil
}
func (UnimplementedServer) SemanticTokensFullDelta(ctx context.Context, params *protocol.SemanticTokensDeltaParams) (result interface{}, err error) {
	return nil, nil
}
func (UnimplementedServer) SemanticTokensRange(ctx context.Context, params *protocol.SemanticTokensRangeParams) (result *protocol.SemanticTokens, err error) {
	return nil, nil
}
func (UnimplementedServer) SemanticTokensRefresh(ctx context.Context) (err error) {
	return nil
}
func (UnimplementedServer) LinkedEditingRange(ctx context.Context, params *protocol.LinkedEditingRangeParams) (result *protocol.LinkedEditingRanges, err error) {
	return nil, nil
}
func (UnimplementedServer) Moniker(ctx context.Context, params *protocol.MonikerParams) (result []protocol.Moniker, err error) {
	return nil, nil
}
func (UnimplementedServer) Request(ctx context.Context, method string, params interface{}) (result interface{}, err error) {
	return nil, nil
}
